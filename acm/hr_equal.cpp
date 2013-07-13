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
#define pb push_back

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;



int main(){
  ll a[10001];
  a[0] = 0;
  a[1] = 1; a[2] = 1;
  a[3] = 2; a[4] = 2; a[5] = 1;

  f (i, 6, 10001){
    a[i] = min(min(a[i - 1], a[i - 2]), a[i - 5]) + 1;
  }
  
  int t; cin >> t;
  
  while (t--){
    int dp[10001];
    int n;
    cin >> n;
    fr (i, n){
      cin >> dp[i];
    }
    sort(dp, dp + n);
    ll res = 0;
    f (i, 1, n){
      res += a[dp[i] - dp[0]];
    }
    cout << res << endl;
  }
}
