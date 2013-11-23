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

#define si(x) scanf("%d\n",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  int t;
  si(t); int inc = 1;
  while (t--){
    char cx[500];
    char cx2[500];
    cin.getline(cx, 500);
    int n = 0;
    fr (i, strlen(cx)){
      if (cx[i] == ')' || cx[i] == '(' || cx[i] == ':'){
	cx2[n] = cx[i]; n++;
      }
    }
    cx2[n] = '\0';
    int dp[n + 1][n + 1];
    fr (i, n + 1){
      fr (j, n + 1){
	dp[i][j] = 0;
      }
    }
    dp[0][0] = 1; int cur = 0;
    fr (i, n){
      if (cx2[i] == '('){
	fr (j, n){
	  dp[i + 1][j + 1]  += dp[i][j];
	}
	if (i > 0 && cx2[i - 1] == ':'){
	  fr (j, n + 1){
	    dp[i + 1][j] += dp[i - 1][j];
	  }
	}
      } else if (cx2[i] == ')'){
	fr (j, n){
	  dp[i + 1][j]  += dp[i][j + 1];
	}
	if (i > 0 && cx2[i - 1] == ':'){
	  fr (j, n + 1){
	    dp[i + 1][j] += dp[i - 1][j];
	  }
	}	
      } else {
	fr (j, n + 1){
	  dp[i + 1][j]  += dp[i][j];
	}
      }
    }
    /*
    cout << cx2 << endl;
    cout << "n " << n << endl;
    fr (i, n + 1){
      fr (j, n + 1){
	cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    */
    if (dp[n][0] > 0){
      printf("Case #%d: YES\n", inc);
    } else {
      printf("Case #%d: NO\n", inc);
    }
    inc++;
  }
}
