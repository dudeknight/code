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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

ll gcd(ll a, ll b){
  if (b - a == 1) {
    return b;
  }
  if (a == 1){
    return b;
  } else if (b % a == 0){
    return a;
  } else {
    return gcd(b % a, a);
  }  
}

int sz = 100001;

int dp[100001][10];


void pre(){
  f (i, 0, sz){
    dp[i][0] = 1;
  }
  
  f (i, 2, sz){
    if (dp[i][0] == 1){
      for (int j = i; j < sz; j += i){
	dp[j][dp[j][0]] = i; dp[j][0]++;
      }
    }
  }
  
}


int main(){
  pre();
  int n;
  si(n);
  int a[n];
  fr (i, n){
    si(a[i]);
  }

  int *b;
  if (a[0] == 1){
    b = a + 1; n--;
  } else {
    b = a;
  }
  int dp6[sz];
  fr (i, sz){
    dp6[i] = 0;
  }  
  fr (i, n){
    int bx = 0;
    int y = b[i];
    f (j, 1, dp[y][0]){
      bx = max(bx, dp6[dp[y][j]]);
    }
    bx++;
    f (j, 1, dp[y][0]){
      dp6[dp[y][j]] = bx;
    }    
  }

  int maxi = 1;
  fr (i, sz){
    maxi = max(dp6[i], maxi);
  }
  printf("%d\n", maxi);
  return 0;
}
