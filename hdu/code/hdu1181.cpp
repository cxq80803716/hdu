#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
vector<int>map[30];
string str;
int visit[30],flag;
queue<int>q;
void bfs(int s,char m)
{
    int i;
    visit[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        for(i=0;i<map[e].size();i++)
        {
            int sbsbsb=map[e][i];
            if(map[e][i]==m-'a')
            {
                flag=1;
                break;
            }
            if(map[e][i]&&!visit[map[e][i]])
            {
                q.push(map[e][i]);
                visit[map[e][i]]=1;
            }
        }
    }
    while(!q.empty())
        q.pop();
    for(i=0;i<30;i++)
        map[i].clear();
}
int main()
{
    while(cin>>str)
    {
        memset(visit,0,sizeof(visit));
        int len=str.length();
        flag=0;
        map[str[0]-'a'].push_back(str[len-1]-'a');
        while(cin>>str)
        {
            if(!str.compare("0"))
                break;
            len=str.length();
            map[str[0]-'a'].push_back(str[len-1]-'a');
        }
        bfs('b'-'a','m');
        if(!flag)
            cout<<"No."<<endl;
        else
            cout<<"Yes."<<endl;
    }
    return 0;
}