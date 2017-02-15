#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 51;

bool ans[125002],tmp[125002];
int p[MAX],m[MAX],n;

void maxx(int &a,int &b){
	int tmp;
	if(a<b){
		tmp = a;
		a = b;
		b = tmp;
	}
}

void work(int limit){
    int i,j,k;

    memset(ans,0,sizeof(ans));
    memset(tmp,0,sizeof(tmp));

	for(i=0;i<=m[0];++i){
		ans[i*p[0]] = true;
	}

	for(i=1;i<n;++i){
		for(j=0;j<=limit;++j){
			for(k=0;k<=m[i] && j+k*p[i]<=limit;++k){
				if(tmp[j+k*p[i]] || ans[j]){
					tmp[j+k*p[i]] = true;
				}
			}
		}

		for(j=0;j<=limit;++j){
			ans[j] = tmp[j];
			tmp[j] = false;
		}
	}
    
}

int main(){
    //freopen("in.txt","r",stdin);
    //(author : CSDN iaccepted)
    int all,vl,vr,i;
	while(scanf("%d",&n)!=EOF){
		if(n<0)break;
		all = 0;
		for(i=0;i<n;++i){
			scanf("%d %d",&p[i],&m[i]);
			all += p[i] * m[i];
		}
		work((all + 1)/2);
		for(i=(all + 1)/2;i>=0;--i){
			if(ans[i]){
				vl = i;
				break;
			}
		}
		vr = all - vl;
		maxx(vl,vr);
		printf("%d %d\n",vl,vr);
	}
    return 0;
}