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

ll mod = 420047;
ll m, n, k;
ll res = 0;

int dp[2][51][16][51];

void case1(){
  fr (i, n + 1){
    fr (j, m + 1){
      fr (p, k + 1){
	dp[0][i][j][p] = 0;
	dp[1][i][j][p] = 0;
      }
    }
  }
  
  fr (i, n + 1){
    fr (j, m + 1){
      dp[0][i][j][0] = 1;
      dp[1][i][j][0] = 0;
    }
  }

  f (i, 1, k + 1){
    f (x, 1, n + 1){
      f (y, 1, m + 1){
	dp[0][x][y][n
      }
    }
  }
  

}

void case2(){

}

int main(){
  fr (i, 34){
    sll(m); sll(n); sll(k);
    if (n <= 50){
      case1();
    } else {
      case2();
    }
    printf("%lld\n", res);
  }
  return 0;
}
