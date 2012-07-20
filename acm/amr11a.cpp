#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500][500];
int dp[500][500];



int main(){
	int t,r,c,mini,i,j,k;cin>>t;
	while(t--){
		cin>>r>>c;
		for(i=0;i<r;i++){
			for(j=0;j<c-1;j++)
				scanf("%d ",&arr[i][j]);
			scanf("%d \n",&arr[i][c-1]);	
		}
		dp[r-1][c-1]=1;
		for(i=c-2;i>=0;i--){
			if(arr[r-1][i]>=dp[r-1][i+1])
				dp[r-1][i]=1;
			else
				dp[r-1][i]=dp[r-1][i+1]-arr[r-1][i];
		}
		for(i=r-2;i>=0;i--){
			if(arr[i][c-1]>=dp[i+1][c-1])
				dp[i][c-1]=1;
			else
				dp[i][c-1]=dp[i+1][c-1]-arr[i][c-1];
			for(k=c-2;k>=0;k--){
				mini=min(dp[i][k+1],dp[i+1][k]);
				if(arr[i][k]>=mini)
					dp[i][k]=1;
				else
					dp[i][k]=mini-arr[i][k];
			}
		}
		printf("%d \n",dp[0][0]);

	}

	return 0;
}



