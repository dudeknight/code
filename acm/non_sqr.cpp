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
#define sll(x) scanf("%l64d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int sum_d(ll x){
  int res = 0;
  while (x){
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main(){
  ll n;
  cin >> n;

  ll res = -1;
  f (i, 1, 18 * 9 + 1){
    ll x = (ll) i;
    ll y = 4 * n + x * x;
    ll t = (ll)sqrt(y);
    if (t * t == y && (t - x) % 2 == 0 && sum_d((t -x) / 2) == i){
      ll tmp = (t - x) / 2;
      res = (res == -1) ? tmp : min(tmp, res);
    }
  }
  cout << res << endl;
  return 0;
}
