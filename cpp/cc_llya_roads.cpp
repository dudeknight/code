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

ll MAX = 10000000000000000LL;



int main(){
  vector<int> st[300];
  vector<int> ed[300];


  int n, m, ki;
  si(n); si(m); si(ki);
  ll temp[n][n];

  fr (i, n){
    fr (j, n){
      temp[i][j] = MAX;
    }
  }

	    

  fr (i, m){
    int l, r; ll c;
    si(l); si(r); sll(c); l--; r--;
    temp[l][r] = min(temp[l][r], c);
    
  }

  /*
  cout << "temp print out 1 \n";
  fr (i, n){
    fr (j, n){
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  */


  ll mini[n];
  fr (i, n){
    mini[i] = MAX;
  }
 
  fr (i, n){
    ll mini_row = MAX;
    for (int j = n - 1; j >= i; j--){
      ll one = min(temp[i][j], mini_row);
      one = min(one, mini[j]);
      temp[i][j] = one;
      mini_row = min(mini_row, one);
      mini[j] = min(mini[j], one);
    }    
  }

  /*
  cout << "temp print out 1.5 \n";
  fr (i, n){
    fr (j, n){
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  */


  fr (k, n){
    fr (i, n){
      f (j, i + 1, n){
	if (i <= k &&  k <= j && temp[i][k] + temp[k + 1][j] < temp[i][j]){
	  temp[i][j] = temp[i][k] + temp[k + 1][j];
	}
      }
    }
  }

  /*
  cout << "temp print out 2 \n";
  fr (i, n){
    fr (j, n){
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  */

  ll dp[n][n + 1];
  fr (i, n){
    fr (j, n + 1){
      dp[i][j]  = MAX;
    }
    dp[i][0] = 0;
  }
 
  dp[0][1] = temp[0][0];
  
  f (i, 1, n){
    fr (k, n + 1){
      dp[i][k] = dp[i - 1][k];
      if (k <= i + 1){
	dp[i][k] = min(dp[i][k], temp[0][i]);
      }
      fr (j, i){
	/*
	if (i == 9 && j == 5){
	  cout << "k " << k << endl;
	  cout << "bt " << dp[i][k] << " " << dp[j][max(0, k - (i - j))] << "  " <<  temp[j + 1][i] << endl;
	}
	*/
	dp[i][k] = min(dp[i][k], dp[j][max(0, k - (i - j))] + temp[j + 1][i]);
      }
    }
  }

  /*
  cout << "dp print \n";
  fr (i, n){
    fr (j, n + 1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  

  cout << "k print " << ki << endl; */
  
  if (dp[n - 1][ki] == MAX){
    cout << -1 << endl;
  } else {
    cout << dp[n - 1][ki] << endl;
  }
  
  
  
  

}
