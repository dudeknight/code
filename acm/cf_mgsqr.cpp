// written by lonerdude(dvdreddy)
// all rights reserved
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

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int dp[3][3];
  int a[3];
  int tot_sum = 0;
  fr (i, 3){
    a[i] = 0;
    fr (j, 3){
      si(dp[i][j]);
      a[i] += dp[i][j];
      tot_sum += dp[i][j];
    }
  }
  tot_sum /= 2;
  fr (i, 3){
    dp[i][i] = tot_sum - a[i];
  }

  fr (i, 3){
    fr (j, 3){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
