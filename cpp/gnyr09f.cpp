//the template by dvdreddy

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int sz=101;

int dp[101][101][2];

int main(){

  fr(i,sz){
    fr(j,sz){
      fr(k,2){
	dp[i][j][k]=0;
      }
    }
  }



  dp[1][1][1]=1;
  dp[1][1][0]=0;
  dp[1][0][0]=1;
  dp[1][0][1]=0;
  
  dp[2][0][0]=2;dp[2][0][1]=1;
  dp[2][1][0]=0;dp[2][1][1]=1;
  


  f(i,3,sz){
    fr(j,i){
      dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
      dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
    }
   
  }
  

  
  int t,n,k,c;
  s(t);
  while(t--){
    s(c);s(n);s(k);
    printf("%d %d\n",c,dp[n][k][0]+dp[n][k][1]);
    

  }
  
  return 0;

}
