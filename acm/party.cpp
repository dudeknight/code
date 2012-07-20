#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int dp[101][501];
	while(n!=0 && k!=0){
		int val,par;
		dp[0][0]=0;
		for(int i=1;i<n+1;i++)
			dp[0][i]=-1;
		for(int i=1;i<k+1;i++){
			cin>>val>>par;
			for(int j=0;j<val&&j<n+1;j++)
				dp[i][j]=dp[i-1][j];
			for(int j=val;j<n+1;j++){
				if(dp[i-1][j-val]!=-1){
					dp[i][j]=max(par+dp[i-1][j-val],dp[i-1][j]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		par=0;
		val=0;
		for(int i=0;i<n+1;i++){
			if(par<dp[k][i]){
				par=dp[k][i];val=i;
			}
		}
		cout<<val<<" "<<par<<endl;
		cin>>n>>k;
	}
	return 0;
}
		

