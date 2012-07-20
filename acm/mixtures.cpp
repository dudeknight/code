#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//the variables
	int dp[100][100];
	int dp_val[100][100];
	int a[100];
	int n;
//the function
int dp_m(int i,int j){
		//cout<<"in dp_m "<<i<<j<<endl;
		if(dp[i][j]!=-1) return dp[i][j];
		else if(i==j-1){
			dp[i][j]=a[i]*a[j];
			dp_val[i][j]=(a[i]+a[j])%100;
		}
		else{
			int min=1000000;
			for(int k=i;k<j;k++){
				int v_l=dp_m(i,k);
				int v_r=dp_m(k+1,j);
				if(min>(dp_val[i][k]*dp_val[k+1][j]+v_l+v_r)){
					min=dp_val[i][k]*dp_val[k+1][j]+v_l+v_r;
					dp_val[i][j]=(dp_val[i][k]+dp_val[k+1][j])%100;		
				}
			}
			dp[i][j]=min;
		}
		return dp[i][j];
}

int main(){
	cin>>n;
	while(!cin.eof()){
		memset(dp,-1,sizeof(dp));
		for (int i=0;i<n;i++){
			cin>>a[i];
			dp[i][i]=0;
			dp_val[i][i]=a[i];
		}
		cout<<dp_m(0,n-1)<<endl;
		cin>>n;
	}
	return 0;
}
