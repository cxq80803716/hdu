#coding:utf-8
import urllib,urllib2
import cookielib
import logging
import re
import lxml.html
from time import sleep
from Downloader import Downloader

seed_url = "http://acm.hdu.edu.cn"
login_url = "/userloginex.php?action=login"
status_url = "/status.php"
submit_url = "/submit.php?action=submit"
class hdu:
    def __init__(self):
        self.pid = 1000
        self.code = None
        self.headers ={"User-Agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.76 Mobile Safari/537.36"}
        cj = cookielib.CookieJar()
        opener=urllib2.build_opener(urllib2.HTTPCookieProcessor(cj),urllib2.HTTPHandler)
        urllib2.install_opener(opener)
    
    def login(self,username,password):
        data = {'username': username,
                'userpass': password,
                'login': 'Sign In'}
        try:
            data = urllib.urlencode(data,'utf-8')
            request=urllib2.Request(seed_url+login_url,data,self.headers)
            response = urllib2.urlopen(request, timeout=10)
            html = response.read()#get the html
            if html.find('Sign Out')==-1:
                return False
            return True
        except:
            return False
        
    def submit(self,problemid,language,code):
        postdata = {'problemid':problemid,
                    'language' :language,
                    'usercode' : code,
                    'check': '1'   
                }
        try:
            self.code = code
            self.pid = problemid
            postdata = urllib.urlencode(postdata,'utf-8')
            request=urllib2.Request(seed_url+submit_url,postdata,self.headers)
            response = urllib2.urlopen(request, timeout=10)
            sleep(1)
            if(response.code!=200 and response.code!=302):
                logging.error("submit fail!")
                return False 
            print 'submit success'
            return True
        except:
            logging.error("submit fail!")
            return False
    
    def get_status(self,username):
        try:
            D = Downloader()
            html = str(D(seed_url+status_url))
            regex = '<table[^>]+>([\s\S]*?)</table>'
            table = re.findall(regex, html)[1]
            regex = '<tr[^>]+>([\s\S]*?)</tr>'
            L = re.findall(regex, table)
            data = ''
            for result in L :
                if re.search(username, result):
                    data = result
                    break
            if data == '': return None
            regex = '<font[^>]+>(.*?)</font>'
            status = re.findall(regex, data)[0]
            if status == 'Compiling' or status == 'Queuing' or status == 'Running' :
                return self.get_status(username)
            else:  
                return status
        except:
            return None
    
# if __name__=='__main__':
#     H=hdu()
        
