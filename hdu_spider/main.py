#-*-coding:utf-8-*-
import urllib
import os
from get_link_from_baidu import get_link_from_baidu
from get_code import get_code
from hdu import hdu
from time import sleep

baseUrl = 'http://www.baidu.com/s'
ojname = "hdu"
code_path = 'code\\'
maxpage = 4 #最大要搜索的页数
user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; it; rv:1.8.1.11) Gecko/20071127 Firefox/2.0.0.11'

def save_code(problemnum,language,code):
    filename = 'hdu'+str(problemnum) +'.cpp' if language == 0 else '.java'
    with open(code_path+'\\'+filename,'w') as f:
        f.write(code)
        
if __name__=='__main__':
    if not os.path.exists(code_path):
        os.makedirs(code_path)
    H =hdu()
    is_login = False
    while is_login == False:
        username = raw_input('请输入hdu账号: ')
        password = raw_input('请输入hdu密码: ')
        if H.login(username, password):
            print '登陆成功!'
            is_login = True
        else: print '登录失败!请重新登录!'
    
    startnum = int(raw_input('请输入开始题号: '))
    endnum = int(raw_input('请输入结束题号: '))
    for problemnum in range(startnum,endnum+1):
        print '开始测试第%d号题: ' % (problemnum)
        retry=0
        Accepted = False
        for page in range(maxpage): #从第一页开始爬
            data = {'wd':ojname + str(problemnum),'pn':str(page)+'0','ct':'2097152'}
            data = urllib.urlencode(data)
            url = baseUrl+'?'+data
            links = get_link_from_baidu(url=url,user_agent=user_agent,ojname=ojname,problemnum=problemnum)
            if len(links) == 0: continue
            code_language = get_code(ojname,problemnum,links) #这是一个列表
            for c_l in code_language:
                code = c_l['usercode']
                language = c_l['language']
                retry +=1
                if H.submit(problemnum, language, code):
                    sleep(2)
                    status = H.get_status()
                    print '第%d题的状态为: %s' % (problemnum,status)
                    if status == 'Accepted':
                        save_code(problemnum,language,code)
                        Accepted = True
                    elif retry==10 : print '找不到AC代码，跳过此题'
                if Accepted or retry == 10:
                    break
            if Accepted or retry == 10:
                    break
        sleep(1)
    print '程序运行结束!5秒后自动关闭'
    sleep(5)