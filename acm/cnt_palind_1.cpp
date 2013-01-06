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

#define f(i,a,b) for(int i = a; i < b; i++)
#define fr(i,n)  f(i,0,n)

#define rf(i,a,b) for(int i = a; i >= b; i--)
#define rfr(i,n)  rf(i, n - 1, 0)
typedef long long ll;


char st[100][100010];
int dp[2][100][100010];
int main(){
  
  int n, m;
  s(n); s(m);
  fr (i, n){ 
    ss(st[i]);
  }
 
  int res = 0;
  int px , py;
  int x = 0;
  bool strk = true;
  bool flg;
  fr (i, n){
    dp[0][i][0] = 1;
    strk = true;
    
    f (j, 1, m){
      x = dp[0][i][j - 1];
      if (j - x - 1 > 0){
	if (st[i][j - x - 1] == st[i][j]){
	  dp[0][i][j] = x + 2;
	  if (st[i][j] != st[i][j - 1]){
	    strk = false;
	  }
	} else if (strk && st[i][j - 1] == st[i][j]){
	  dp[0][i][j] = x + 1;
	} else {
	  px = j - x;
	  py = 1;
	  while (px < j){
	    if (st[i][px] == st[i][j]){
	      flg = true;
	      for (int k = px + 1; k < j; k++){
		if (st[i][k] != st[i][j - k + px]){
		  flg = false;
		  break;
		}
	      }
	      if (flg){
		py = j - px + 1;
		break;
	      }
	    } else {
	      px++;
	    }
	  }
	  dp[0][i][j] = px;
	  if (px == 1){
	    strk = true;
	  }
	}	  
      } else {
	if (strk && st[i][j - 1] == st[i][j]){
	  dp[0][i][j] = x + 1;
	} else {
	  px = 0;
	  py = 1;
	  while (px < j){
	    if (st[i][px] == st[i][j]){
	      flg = true;
	      for (int k = px + 1; k < j; k++){
		if (st[i][k] != st[i][j - k + px]){
		  flg = false;
		  break;
		}
	      }
	      if (flg){
		py = j - px + 1;
		break;
	      }
	    } else {
	      px++;
	    }
	  }
	  dp[0][i][j] = px;
	  if (px == 1){
	    strk = true;
	  }	  
	}
      }
    }
    
    dp[1][i][m - 1] = 1;
    strk = true;
    for (int j = m - 1; j >= 0; j--){
      x = dp[0][i][j + 1];
      if (j + x + 1 < m){
	if (st[i][j + x + 1] == st[i][j]){
	  dp[0][i][j] = x + 2;
	  if (st[i][j] != st[i][j + 1]){
	    strk = false;
	  }
	} else if (strk && st[i][j + 1] == st[i][j]){
	  dp[0][i][j] = x + 1;
	} else {
	if (st[i][j + 1] == st[i][j] && strk){
	  dp[0][i][j] = x + 1;
	} else {
	  px = j + x;
	  py = 1;
	  while (px > j){
	    if (st[i][px] == st[i][j]){
	      flg = true;
	      for (int k = j + 1; k < px; k++){
		if (st[i][k] != st[i][px - k + j]){
		  flg = false;
		  break;
		}
	      }
	      if (flg){
		py = px - j + 1;
		break;
	      }
	    } else {
	      px--;
	    }
	  }
	  dp[0][i][j] = px;
	  if (px == 1){
	    strk = true;
	  }	 
	}	  
      } else {
	  if (st[i][j + 1] == st[i][j] && strk){
	    dp[0][i][j] = x + 1;
	  } else {
	    px = m - 1;
	    py = 1;
	    while (px > j){
	      if (st[i][px] == st[i][j]){
		flg = true;
		for (int k = j + 1; k < px; k++){
		  if (st[i][k] != st[i][px - k + j]){
		    flg = false;
		    break;
		}
		}
		if (flg){
		  py = px - j + 1;
		  break;
		}
	      } else {
		px--;
	      }
	    }
	    dp[0][i][j] = px;
	    if (px == 1){
	      strk = true;
	    }	  	    
	  }
	}
      }
    }
  }
  
  



  fr (i, n){
    f (j, i + 1, n){
      fr (p, m){
	if (st[i][p] == st[j][m -  1 - p]){
	  int maxi = max(dp[1][i][p + 1], dp[0][j][m - 1 - p - 1]);
	  res = max(res, 2 * p + 2 + maxi);
	} else {
	  break;
	}
      }

      fr (p, m){
	if (st[j][p] == st[i][m -  1 - p]){
	  int maxi = max(dp[1][j][p + 1], dp[0][i][m - 1 - p - 1]);
	  res = max(res, 2 * p + 2 + maxi);
	} else {
	  break;
	}
      }
    }	
  }     

  if (res >= m){
    cout << res << endl;
    return 0;
  }

  fr (i, n){
    res = max(res, dp[0][i][m - 1]);
    res = max(res, dp[1][i][0]);
  }
  cout << res << endl;
  return 0;

}
