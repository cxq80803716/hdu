#include "stdio.h"

int main(){
	int i, j;
	int dp[31];
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	/*dp[i] = dp[2]*dp[i-2] + 2*(dp[i-4]+dp[i-6]+...+dp[i-(i-2)]+dp[0])*/
	for(i=3; i<=30; i++){
		if(i%2){
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[2]*dp[i-2];
		for(j=i-4; j>=0; j-=2){
			dp[i] += 2*dp[j];
		}
	}
	while(scanf("%d", &i), i>=0){
		printf("%d\n", dp[i]);
	}
	return 0;
}