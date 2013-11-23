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

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


char st[100][100010];
int dp[2][100][100010];
int main(){
  
  int n, m;
  s(n); s(m);
  fr (i, n){ 
    ss(st[i]);
  }
  
  fr (i, n){
    dp[0][i][0] = 0;
    dp[1][i][m] = 0;
    dp[0][i][1] = 1;
    bool strk = true;
    f (j, 2, m){
      int l = dp[0][i][j - 1];
      if (l == 1){
	if (j - 3 >=0 && st[i][j - 1] == st[i][j - 3]){
	  dp[0][i][j] = 3;
	  strk = false;
	}
	else if (st[i][j - 1] == st[i][j - 2]){
	  dp[0][i][j] = 2;
	  strk = true;
	} else {
	  dp[0][i][j] = 1;
	  strk = false;
	}
      } else if (strk && st[i][j - 1] == st[i][j - 2]){
	dp[0][i][j] = dp[0][i][j - 1] + 1;	
      } else {
	if (j - 2 - l >= 0 && ){	  
	  
	}
      }
    }
    

  }
  



}
