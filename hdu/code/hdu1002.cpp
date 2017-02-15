#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
char a[1004],b[1004];
int  an[1004],bn[1004];
int lena,lenb;

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        memset(an,0,sizeof(an));
        memset(bn,0,sizeof(bn));
        cin>>a>>b;
        int c=0,d=0;
        lena=strlen(a);lenb=strlen(b);
        for(int i=lena-1;i>=0;i--)
             an[c++]=a[i]-'0';
        for(int i=lenb-1;i>=0;i--)
             bn[d++]=b[i]-'0';
        int maxlen; maxlen=lena>=lenb?lena:lenb;
        for(int i=0;i<maxlen;i++)
        {
            an[i]+=bn[i];
            if(an[i]>=10)
            {
                an[i+1]++;
                an[i]-=10;
            }
        }
        int j;
        for(j=1003;j>=0;j--)
            if(an[j]!=0)
            break;
        cout<<"Case "<<k<<":"<<endl;
        cout<<a<<" + "<<b<<" = ";
        for(;j>=0;j--)
            cout<<an[j];
        cout<<endl;
        if(k!=t)
            cout<<endl;
    }
    return 0;
}
