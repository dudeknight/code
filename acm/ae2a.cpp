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

#define size 1001

double dp[size][6*size+1];

int main(){
  int t;
  s(t);
  fr(i,size){
    fr(j,6*size+1){
      dp[i][j]=0;
    }
  }
  f(i,1,7){
    dp[1][i]=100.00/6;
  }
 
  f(i,2,size){
    f(j,i,6*i+1){
      f(k,1,7){
	if(j-k<1) break;
	dp[i][j]+=dp[i-1][j-k];
      }
      dp[i][j]/=6.0;
      if(dp[i][j]<0.01)
	break;
    }
  }
  // printf("%lld\n",dp[400][1200]);
  //return 0;
  while(t--){
    int n,k;s(n);s(k);
    if(n>1000 || (k<n || k>6*n)){
      printf("0\n");
      continue;
    }
    else{
      int res=(int)dp[n][k];
      printf("%d\n",res);

    }


  }

  return 0;





}
