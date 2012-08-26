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
int dp1[1500][1500];
int dp2[1500][1500];
int dp3[1500][1500];

char c1[1510];
char c2[1520];

int main(){
  int t, k, n;
  s(t);
  while (t--){
    s(k);
    ss(c1);
    ss(c2);
    n = strlen(c1);
    //cout << c1 << " " << c2 << endl;
    fr (i, n){
      fr (j, n){
	dp1[i][j] = 0;
	dp2[i][j] = 0;
	dp3[i][j] = 0;
      }
    }
    
    fr (i, n){
      if (c1[i] == c2[0]){
	dp3[i][0] = 1;
      }
      if (c1[0] == c2[i]){
	dp3[0][i] = 1;
      }
    }
    
    f (i, 1, n){
      f (j, 1, n){
	if (c1[i] == c2[j]){
	  dp3[i][j] = dp3[i - 1][j - 1] + 1;
	}
      }
    }
    
    fr (i, n){
      if (c1[n - 1] == c2[i]){
	dp1[n - 1][i] = 1;
	dp2[n - 1][i] = 0;
      } else {
	if (k != 0){
	  dp1[n - 1][i] = 1;
	  dp2[n - 1][i] = 1;
	}
      }
    }
    
    fr (i, n){
      if (c2[n - 1] == c1[i]){
	dp1[i][n - 1] = 1;
	dp2[i][n - 1] = 0;
      } else {
	if (k != 0){
	  dp1[i][n - 1] = 1;
	  dp2[i][n - 1] = 1;
	}
      }
    }
    
    for (int i = n - 2; i >= 0; i--){
      for(int j = n - 2; j >= 0; j--){
	if (c1[i] == c2[j]){
	  dp1[i][j] = dp1[i + 1][j + 1] + 1;
	  dp2[i][j] = dp2[i + 1][j + 1];
	} else {
	  if (dp2[i + 1][j + 1] < k){
	    dp1[i][j] = dp1[i + 1][j + 1] + 1;
	    dp2[i][j] = dp2[i + 1][j + 1] + 1;
	  } else {
	    int endx = i + dp1[i + 1][j + 1];
	    int endy = j + dp1[i + 1][j + 1];
	    dp1[i][j] = dp1[i + 1][j + 1] - dp3[endx][endy];
	    dp2[i][j] = dp2[i + 1][j + 1];
	  }
	}
      }
    }
    /*
    cout << n << " dp1 \n";
    fr (i, n){
      fr (j, n){
	cout << dp1[i][j] << " ";
      }
      cout << endl;
    }
    cout << k << " dp2 \n";
    fr (i, n){
      fr (j, n){
	cout << dp2[i][j] << " ";
      }
      cout << endl;
    }
    cout << " dp3 \n";
    fr (i, n){
      fr (j, n){
	cout << dp3[i][j] << " ";
      }
      cout << endl;
    }
    */
    int res = 0;
    fr (i, n){
      fr (j, n){
	res = max(res, dp1[i][j]);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
