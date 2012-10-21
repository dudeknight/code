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

#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


ll dp[1000001];
ll dp2[1000001];
int max_size = 1000001;

int gcd (int a, int b){
  if (a == 0){
    return 1;
  }
  if (a == 1){
    return 1;
  } else {
    return (b % a, a);
  }  
}

int main(){
  dp[1] = 1; dp2[1] =1;
  dp[2] = 2; dp2[2] = 2;
  dp[3] = 6; dp2[3] = 6;
  f (i, 4, max_size){
    if (i % 2){
      dp[i] = (ll)i * (ll)(i - 1) * (ll) (i - 2);
    } else if (i % 3) {
      ll x = (ll)i * (ll)(i - 1) * (ll) (i - 3);
      ll y = (ll)i * (ll)(i - 1) * (ll) (i - 2); y /= 2;
      ll z = (ll)(i - 3) * (ll)(i - 1) * (ll) (i - 2);
      dp[i] = max(x, y); dp[i] = max(dp[i], z);
    } else {
      ll maxi = dp[i -1];
      f (k, 1, 10){
	f (j, k + 1, 10){
	  ll x =  (ll) (i - k) * (ll) (i - j);
	  ll y = (ll) gcd (i - j, i - k); 
	  y = (ll) gcd ((int) y, i);
	  maxi = max(maxi, ((ll) i * x) / y);
	}	
      }      
      dp[i] = maxi;
    }
    if (dp[i] <= 0){
      cout << i << endl;
    }
  }
  int n;
  cin >> n;
  cout << dp[n] << endl;
}

