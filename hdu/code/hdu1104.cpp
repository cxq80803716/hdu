#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e6;
int n,k,m;
int key;
int v[maxn + 10];
int flag;

struct node{
    int x;
    int step;
    string path;
};
node ans;


void bfs()

{
    memset(v,0,sizeof(v));
    queue<node> q;
    node first;
    first.x = n;
    first.step = 0;
    first.path = "";
    q.push(first);
    v[(first.x % k + k) % k] = 1;
    while(!q.empty())
    {
        node head = q.front();
        q.pop();
        if((head.x % k + k) % k == key)
        {
            flag = 1;
            ans = head;
            return ;
        }
        for(int i = 0;i < 4;++i)
        {
            node t;
            if(i == 0)
            {
                t.x = (head.x + m) % (k * m);
                if(!v[(t.x % k + k) % k])
                {
                    t.step = head.step + 1;
                    t.path = head.path + "+";
                    q.push(t);
                    v[(t.x % k + k) % k] = 1;
                }
            }
            else if(i == 1)
            {
                t.x = (head.x - m) % (k * m);
                if(!v[(t.x % k + k) % k])
                {
                    t.step = head.step + 1;
                    t.path = head.path + "-";
                    q.push(t);
                    v[(t.x % k + k) % k] = 1;
                }
            }
            else if(i == 2)
            {
                t.x = (head.x * m) % (k * m);
                if(!v[(t.x % k + k) % k])
                {
                    t.step = head.step + 1;
                    t.path = head.path + "*";
                    q.push(t);
                    v[(t.x % k + k) % k] = 1;
                }
            }
            else
            {
                t.x = (head.x % m + m) % m % (k * m);
                if(!v[(t.x % k + k) % k])
                {
                    t.step = head.step + 1;
                    t.path = head.path + "%";
                    q.push(t);
                    v[(t.x % k + k) % k] = 1;
                }
            }
        }
    }
}

int main()

{
    while(~scanf("%d%d%d",&n,&k,&m))
    {
        if(n == 0 && k == 0 && m == 0)
            break;

        key = ((n + 1) % k + k) % k;
        flag = 0;
        bfs();
        if(flag)
        {
            cout << ans.step << endl;
            cout << ans.path << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}
