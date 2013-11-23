#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[10001][500];
int v[500];
int w[500];

int main(){
	int t;
	cin>>t;
	while(t>0){
		int e,f,n,nw;
		cin>>e>>f;
		nw=f-e;
		cin>>n;
//		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>v[i]>>w[i];
		}
		for(int j=1;j<=nw;j++){
			if(j%w[0]==0){
				dp[j][0]=(j/w[0])*v[0];
			}
			else{
				dp[j][0]=-2;
			}	
		}
		dp[0][0]=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<=nw;j++){
				if(j<w[i]){
					dp[j][i]=dp[j][i-1];
				}
				else{
					int val1=dp[j][i-1];
					int val2=dp[j-w[i]][i];
					if(val1==-2 && val2!=-2)
						dp[j][i]=val2+v[i];
					else if(val2==-2)
						dp[j][i]=val1;
					else
						dp[j][i]=min(val1,v[i]+val2);
				}
			}
		}
		int val=dp[nw][n-1];
		if(val!=-2)
        		cout<<"The minimum amount of money in the piggy-bank is "<<val<<".\n";
	        else
			cout<<"This is impossible.\n";
		t--;
	}
	return 0;
}
