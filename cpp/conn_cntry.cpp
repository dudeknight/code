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
typedef long double ld;

ld a[31][436];
ld dp[436];
ld fin[436];

int main(){
  fr (i, 31){
    fr (j, 436){
      a[i][j] = 0.0;
    }
  }
  
  dp[0] = 1.0;
  f (i, 1, 436){
    dp[i] = dp[i - 1] * ((ld) i);
  }
  //cout << "Dp " << dp[435] << endl;
  int n; s(n);
  int ed = (n * (n - 1)) / 2;
  ld res = 0;
  cout << n << endl;
  a[1][0] = (ld) 1.0;
  a[2][1] = (ld) 1.0;
  f (i, 3, n){
    f (j, i - 1, (i * (i - 1) / 2) + 1){
      ld t1 = (ld) i;
      //cout << "i j " << i << " " << j << endl;
      f (k, 1, i - 1){
	f (p, 0, j){
	  //cout << k << " " << p <<  " " << a[k][p] << " " << a[i - k][j - 1 - p] << endl;
	  a[i][j] += (a[k][p] * a[i - k][j - 1 - p] * t1 * k * (i - k));
	}
	t1 = t1 * ((ld) (i - k)) / ((ld)(k + 1));
      }
      a[i][j] += a[i][j - 1] * ((ld)((i * (i - 1) / 2) - (j - 1)));
      //cout << a[i][j] << "|";
    }
    //cout << endl;
  }
  
  fr (i, n){
    fr (j, (i * (i - 1) / 2) + 1){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  

  fr (j, ed + 1){
    fin[j] = 0.0;
  }

  cout << "fin\n";
  f (j, n - 1, ed + 1){
    ld t1 = (ld) n;
    f (k, 1, n){
      f (p, 0, j - 1){
	fin[j] +=  (a[k][p] * a[n - k][j - 1 - p] * t1 * k * (n - k));
      }
      t1 = t1 * ((ld) (n - k)) / ((ld)(k + 1));
    }
    cout << fin[j] << " ";
  }
  cout <<  endl;

  f (i, n - 1, (n * (n - 1) / 2 + 1)){
    res = res + ((ld) i) * (fin[i] * dp[ed - i] / dp[ed]);
  }
  
  int ans = int(res);
  printf("%d\n", ans);
  return 0;
}
