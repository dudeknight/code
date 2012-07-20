#include <iostream>
using namespace std;

int dp[1001][1001];
int main(){
  int n,k;cin>>n>>k;
  if(k==1) {cout<<n<<endl;return 0;}
  for(int i=0;i<k+1;i++){
    for(int j=0;j<n+1;j++){
      dp[i][j]=0;
    }
  }
  
  for(int i=0;i<n+1;i++){
    dp[1][i]=i;
  }
  for(int i=2;i<k+1;i++){
    for(int j=2;j<n+1;j++){
      dp[i][j]=dp[i][j-1]+dp[i-1][j-2];
    }
  }
  cout<<(dp[k][n-1]+dp[k-1][n-3])%1000000003<<endl;
  return 0;


  
}
