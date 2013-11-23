#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int dp[10001];

long long f(long  n){
	if(n<=10000) return dp[n];
	else{
		long long x=f(n/2)+f(n/3)+f(n/4);
		return n>x?n:x;
	}
}


int main(){
	int t;
	//cin>>t;
	
	dp[0]=0;dp[1]=1;
	dp[2]=2;dp[3]=3;
	dp[4]=4;
	
	int i;
	for(i=5;i<10001;i++){
	//		cout<<i<<endl;
		dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}
	long n;
	cin>>n;
	while(!cin.eof()){
		cout<<f(n)<<endl;
		cin>>n;
	}
	return 0;
}
