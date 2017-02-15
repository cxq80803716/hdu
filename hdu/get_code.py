#coding:utf-8

import re
from Downloader import Downloader
import lxml.html

def get_code(ojname,problemnum,links): 
    list = []
    try:
        regex_cnblog = re.compile(u'%s( |)%s([\s\S]*)博客园'%(ojname,problemnum),re.IGNORECASE)
        regex_csdn = re.compile(u'%s( |)%s([\s\S]*)CSDN.NET'%(ojname,problemnum),re.IGNORECASE)
        
        regex0 = re.compile('^(#include([\s\S]*)main())')  #如果是代码里面一定包含 main() 函数,并且是G++代码 
        regex5 = re.compile('^(#import([\s\S]*)main())')   #java代码
        list = [] #存储所有当前爬到的代码
        for link in links:
            D= Downloader()
            html = str(D(link).decode())
            tree = lxml.html.fromstring(html)
            title = tree.cssselect('title')[0].text_content()
            if re.search(regex_cnblog,title) or re.search(regex_csdn, title): 
                html = unicode(html,"utf-8")    
                texts = tree.cssselect('pre')
                for text in texts:
                    text = text.text_content()
                    if(re.search(regex0,text)):
                        data = {'language':0,'usercode':text}
                        list.append(data)
                    elif(re.search(regex5,text)):
                        data = {'language':5,'usercode':text}
                        list.append(data)
    finally:  return list