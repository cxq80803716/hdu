#-*-coding:utf-8-*-

import re
from Downloader import Downloader
import lxml.html

def get_code(ojname,problemnum,links): 
    regex0 = re.compile('^(#include([\s\S]*)main())')  #如果是代码里面一定包含 main() 函数,并且是G++代码 
    regex5 = re.compile('^(#import([\s\S]*)main())')   #java代码
    list = [] #存储所有当前爬到的代码
    for link in links:
        D= Downloader()
        html = D(link)
        html = unicode(html,"utf-8")
        tree = lxml.html.fromstring(html)
        texts = tree.cssselect('pre')
        for text in texts:
            text = text.text_content()
            if(re.search(regex0,text)):
                data = {'language':0,'usercode':text}
                list.append(data)
            elif(re.search(regex5,text)):
                data = {'language':5,'usercode':text}
                list.append(data)
    return list