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

int rec(int cw,int i){
//	cout<<cw<<" "<<i<<endl;
	if(cw<0) return -2;
	if(cw==0) return 0;
//	cout<<"dbg 3 "<<dp[100][20]<<endl;
	if(dp[cw][i]!=-1)
		return dp[cw][i];
	if(i==0){
		if(cw<w[i])
			dp[cw][i]=-2;
		else{
			int val2=rec(cw-w[i],i);
			if(val2!=-2)
				dp[cw][i]=val2+v[i];
			else
				dp[cw][i]=-2;
		}
	}
	else{
//		cout<<"dbg 2 \n";
		if(cw<w[i])
			dp[cw][i]=rec(cw,i-1);
		else {
			int val1=rec(cw,i-1);
			int val2=rec(cw-w[i],i);
			if(val1==-2 && val2!=-2)
				dp[cw][i]=val2+v[i];
			else if(val2==-2)
				dp[cw][i]=val1;
			else
				dp[cw][i]=min(val1,v[i]+val2);
		}
	}
        return dp[cw][i];		
}

int main(){
	int t;
	cin>>t;
	while(t>0){
		int e,f,n,nw;
		cin>>e>>f;
		nw=f-e;
		cin>>n;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>v[i]>>w[i];
		}
	//	cout<<"dbg \n";
		int val=rec(nw,n-1);
		//cout<<"dbg 4"<<val<<endl;
	        if(val!=-2)
        		cout<<"The minimum amount of money in the piggy-bank is "<<val<<".\n";
	        else
			cout<<"This is impossible.\n";
		t--;
	}
	return 0;
}
