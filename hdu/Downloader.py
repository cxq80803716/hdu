#coding:utf-8
from datetime import datetime
import random
import socket
import time
import urllib2
import urlparse
from bs4 import BeautifulSoup

DEFAULT_AGENT = 'cxq'
DEFAULT_DELAY = 5
DEFAULT_RETRIES = 1
DEFAULT_TIMEOUT = 10


class Downloader:
    def __init__(self, delay=DEFAULT_DELAY, user_agent=DEFAULT_AGENT, proxies=None, num_retries=DEFAULT_RETRIES, timeout=DEFAULT_TIMEOUT, opener=None, cache=None):
        socket.setdefaulttimeout(timeout)
        self.throttle = Throttle(delay)
        self.user_agent = user_agent
        self.proxies = proxies
        self.num_retries = num_retries
        self.opener = opener
        self.cache = cache


    def __call__(self, url):
        result = None
        if self.cache:
            try:
                result = self.cache[url]
            except KeyError:
                #如果 url 的cache 不可用
                pass
            else:
                if self.num_retries > 0 and 500 <= result['code'] < 600:
                    # 服务器错误所以忽视 cache中的数据
                    result = None
        if result is None:
            #网页是空的所以重试
            self.throttle.wait(url)
            proxy = random.choice(self.proxies) if self.proxies else None
            headers = {'User-agent': self.user_agent}
            result = self.download(url, headers, proxy=proxy, num_retries=self.num_retries)
            if self.cache:
                # 将result 存入cache 中
                self.cache[url] = result
        return result['html']


    def download(self, url, headers, proxy, num_retries, data=None):
        #print 'download:'+url
        request = urllib2.Request(url,data,headers)
        try:
            response = urllib2.urlopen(request,timeout=10)
            html = response.read()
            code = response.code
        except Exception as e:
            print 'Download error:', str(e)
            html = ''
            if hasattr(e, 'code'):
                code = e.code
                if num_retries > 0 and 500 <= code < 600:
                    # 返回服务器错误码
                    return self._get(url, headers, proxy, num_retries-1, data)
            else:
                code = None
        return {'html': html, 'code': code}


class Throttle:
    """Throttle类是在相同域名下两个网页间的间隔时间
    """
    def __init__(self, delay):
        self.delay = delay
        # timestamp of when a domain was last accessed
        self.domains = {}
        
    def wait(self, url):
        """Delay if have accessed this domain recently
        """
        domain = urlparse.urlsplit(url).netloc
        last_accessed = self.domains.get(domain)
        if self.delay > 0 and last_accessed is not None:
            sleep_secs = self.delay - (datetime.now() - last_accessed).seconds
            if sleep_secs > 0:
                time.sleep(sleep_secs)
        self.domains[domain] = datetime.now()
        