#include<stdio.h>
int a[100010];
int main(){
	int case_number,k=0,i,number,position1,end,thissum,maxsum,begin;
	scanf("%d",&case_number);
	while(case_number--){
		k++;
		scanf("%d",&number);
		for(i=0;i<number;i++)
			scanf("%d",&a[i]);
		position1=begin=end=0;
		maxsum=thissum=a[0];
		for(i=1;i<number;i++){
			if(thissum+a[i]<a[i]){             //如果当前值比a[i]小的话则改为a[i]
				thissum=a[i];
				position1=i;                  //记录下改的位置
			}
			else{
				thissum=thissum+a[i];          
			}
			if(thissum>maxsum){                //当前值比最大值大，则头尾都要改
				maxsum=thissum;
				begin=position1;
				end=i;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,maxsum,begin+1,end+1);
		if(case_number)                        //测试数据之后有空行，一开始也没看见，也WR了。
			printf("\n");
	}
	return 0;
}
