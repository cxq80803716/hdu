#include<stdio.h>
int s[500][4];
int main()
{
	int P,i;
	while (scanf("%d",&P)!=EOF)
	{
		if (P==0) return 0;
		int N=(P-1)/4+1;
		int M=4*N;
		int l=1,r=M;
		for (i=1;i<=N;i++)
		{
			s[i][0]=r--;
			s[i][1]=l++;
			s[i][2]=l++;
			s[i][3]=r--;
		}
		printf("Printing order for %d pages:\n",P);
		for (i=1;i<=N;i++)
		{
			if (!(s[i][0]>P && s[i][1]>P))
			{
				printf("Sheet %d, front:",i);
				if (s[i][0]>P) printf(" Blank, ");
				else printf(" %d, ",s[i][0]);
				if (s[i][1]>P) printf("Blank\n");
				else printf("%d\n",s[i][1]);
			}
			if (!(s[i][2]>P && s[i][3]>P))
			{
				printf("Sheet %d, back :",i);
				if (s[i][2]>P) printf(" Blank, ");
				else printf(" %d, ",s[i][2]);
				if (s[i][3]>P) printf("Blank\n");
				else printf("%d\n",s[i][3]);
			}
		}
	}
	return 0;
}
