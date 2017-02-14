#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int flag[100],s[100],f[5];
long target;

#define res(v,w,x,y,z) v-w*w+x*x*x-y*y*y*y+z*z*z*z*z

int dfs(int step,int len,int n)
{
    if(step == 5)
    {
            if(res(f[0],f[1],f[2],f[3],f[4]) == n)
            return 1;
            return 0;
    }
    for(int i = len; i >= 0; i--)
    {
            if(flag[i])
               continue;
            flag[i] = 1;
            f[step] = s[i];
            if(dfs(step+1,len,n))
                return 1;
            flag[i] = 0;
    }
    return 0;
}

int main()
{
    char str[50];
    while(scanf("%d%s",&target,str)!=EOF)
    {
         if(target == 0 && strcmp(str,"END") == 0)
              break;
         int len = 0;
         while(str[len])
         {
               s[len] = str[len] - 'A' +1;
               flag[len] = 0;
               len++;
         }
         
         sort(s,s+len);
         
         if(dfs(0,len-1,target))
         {
              for(int i = 0 ;i < 5; i++)
              {
                      printf("%c",f[i] + 'A' -1);
              }
              cout<<endl;
         }
         else
         puts("no solution");          
    }
    return 0;
}