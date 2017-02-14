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
        data = urllib.urlencode(data,'utf-8')
        try:
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
        self.code = code
        self.pid = problemid
        postdata = urllib.urlencode(postdata,'utf-8')
        try:
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
    
    def get_name(self):
        try:
            regex = re.compile('<img alt="Author" src="/images/user.png" border=0 height=18 width=18> [\s\S]*?</a>')
            D = Downloader()
            html = D(seed_url)
            text = re.search(regex,html).group()
            name = ''
            flag = False #标记是否出现过>了
            for i in text:
                if i== '>':
                    flag = True
                    continue
                if flag and i=='<':
                    break
                elif flag and i!=' ':
                    name +=i
            return name
        except: return None
    
    def get_status(self):
        #name是该账号的昵称，即在hdu的status页面显示的名字
        name = self.get_name()
        if name == None: return None
        try:
            D = Downloader()
            html = D(seed_url+status_url)
            tree = lxml.html.fromstring(html)
            status_ = tree.cssselect('table.table_text > tr')
            for pos in range(1,len(status_)):
                status = status_[pos]
                status = status.text_content()
                if status.find(name) != -1:
                    id = 27
                    data = ''
                    while str.isalpha(status[id]) or status[id]==' ':
                        data +=status[id]
                        id+=1
                    if data == 'Compiling' or data == 'Queuing' or data == 'Running' :
                        return self.get_status()
                    else:  return data
            return None
        except:  return None
    
# if __name__=='__main__':
#     H=hdu()
#     H.login('80803716', '83613139')
#     name = H.get_name()
#     print name
        
