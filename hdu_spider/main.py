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
maxpage = 4 #���Ҫ������ҳ��
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
        username = raw_input('������hdu�˺�: ')
        password = raw_input('������hdu����: ')
        if H.login(username, password):
            print '��½�ɹ�!'
            is_login = True
        else: print '��¼ʧ��!�����µ�¼!'
    
    startnum = int(raw_input('�����뿪ʼ���: '))
    endnum = int(raw_input('������������: '))
    for problemnum in range(startnum,endnum+1):
        print '��ʼ���Ե�%d����: ' % (problemnum)
        retry=0
        Accepted = False
        for page in range(maxpage): #�ӵ�һҳ��ʼ��
            data = {'wd':ojname + str(problemnum),'pn':str(page)+'0','ct':'2097152'}
            data = urllib.urlencode(data)
            url = baseUrl+'?'+data
            links = get_link_from_baidu(url=url,user_agent=user_agent,ojname=ojname,problemnum=problemnum)
            if len(links) == 0: continue
            code_language = get_code(ojname,problemnum,links) #����һ���б�
            for c_l in code_language:
                code = c_l['usercode']
                language = c_l['language']
                retry +=1
                if H.submit(problemnum, language, code):
                    sleep(2)
                    status = H.get_status()
                    print '��%d���״̬Ϊ: %s' % (problemnum,status)
                    if status == 'Accepted':
                        save_code(problemnum,language,code)
                        Accepted = True
                    elif retry==10 : print '�Ҳ���AC���룬��������'
                if Accepted or retry == 10:
                    break
            if Accepted or retry == 10:
                    break
        sleep(1)
    print '�������н���!5����Զ��ر�'
    sleep(5)