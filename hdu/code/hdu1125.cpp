#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;

bool brr[65536];
int arr[7001];

void FindPrime(void)
{
    int i,j,k;
    
    memset(brr,1,sizeof(brr));
    
    k=0;
    for(i=2;i<65536;++i)
        if(brr[i])
        {
            for(j=i+i;j<65536;j+=i)
                brr[j]=0;
            arr[k]=i;
            ++k;
        }
}

int main()
{
    int x,i;
    FindPrime();
    
    while(scanf("%d",&x)!=EOF)
    {
        
        for(i=0;i<=x && !brr[x];++i)
            if(x%arr[i]==0)
            {
                printf("%d*",arr[i]);
                x/=arr[i];
                --i;
            }
            
            
        printf("%d\n",x);
    }
    
    return 0;
}