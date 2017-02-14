#coding:utf-8
"""
     get the code from baidu
"""
import requests
from bs4 import BeautifulSoup
import re
from Downloader import Downloader

def get_link_from_baidu(url,user_agent=None,num_retries=5,cache=None,\
                 ojname='hdu',problemnum=None,page=0):
    """进入百度页面
    """
    links = []
    try:
        D = Downloader(user_agent=user_agent,num_retries=num_retries,cache=cache)
        html = D(url) #调用Downloader类的__call__方法
        text = str(html)
        soup = BeautifulSoup(text,'html5lib') #通过BeautifulSoup来做匹配
        list_soup = soup.find('div',{'id':'content_left'})
        links = [link.get('href') for link in list_soup.findAll('a',{'class':'c-showurl'})]
        links = get_real_links(links)
        links = [link for link in links if \
                 re.match('http://www.cnblogs.com/',link) or re.match('http://blog.csdn.net/', link)]
    finally:
        return links
    
    
def get_real_links(links):
    real_links = []
    import requests
    for link in links:
        retry = 2
        while(retry>0):
            try:
                header = requests.head(link).headers
                real_links.append(header['location'])
                break
            except Exception as e:
                print str(e)
                retry-=1
                continue
    return real_links
    
    
    