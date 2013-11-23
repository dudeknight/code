#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define  get_int(x) scanf("%lld",&x)
int  pres(int k){return (k&1)^0;}
int  prev(int k){return (k&1)^1;}

long long dp[2][3];


int main(){
  int n;
  scanf("%d",&n);
  int t=1,i;
  while (n){
    //cout<<n<<endl;
    dp[0][0]=1000000000;
    get_int(dp[0][1]);
    get_int(dp[0][1]);
    get_int(dp[0][2]);dp[0][2]+=dp[0][1];
    for(i=1;i<n;i++){
      get_int(dp[pres(i)][0]);
      dp[pres(i)][0]+=min(dp[prev(i)][0],dp[prev(i)][1]);
      get_int(dp[pres(i)][1]);
      dp[pres(i)][1]+=min(min(dp[pres(i)][0],min(dp[prev(i)][1],dp[prev(i)][2])),dp[prev(i)][0]);
      get_int(dp[pres(i)][2]);
      dp[pres(i)][2]+=min(dp[pres(i)][1],min(dp[prev(i)][1],dp[prev(i)][2]));  
    }
    printf("%d. %lld\n",t,dp[prev(n)][1]);
    scanf("%d",&n);
    //cout<<n<<endl;break;
    t++;
  }

  return 0;
}


