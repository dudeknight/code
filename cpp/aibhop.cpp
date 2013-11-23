#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
int dp[6100][6100];
string s;


int main(){
	int t;
	cin>>t;

	while(t>0){
		cin>>s;
		int n=s.size();		
		for(int i=0;i<n;i++)
			dp[i][i]=0;
		for(int j=1;j<n;j++){
			for(int i=0;i<n-j;i++){
				if(s[i]==s[i+j]){
					dp[i][i+j]=dp[i+1][i+j-1];
				}	
				else{
					dp[i][i+j]=min(dp[i+1][i+j],dp[i][i+j-1])+1;
				}
			}
		}
		//	cout<<n<<endl;
		/*	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		cout<<dp[0][n-1]<<endl;
		t--;
	}




}
