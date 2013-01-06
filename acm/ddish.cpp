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
typedef pair<ll, bool> pb;
ll fact[20];
ll f_cnt[20];


pb result(ll x){
  int dig[20];
  bool flg[10];
  fr (i, 10){
    flg[i] = false;
  }
  int cnt = 0;
  ll y = x;
  while (y){
    dig[cnt] = y % 10; cnt++;
    y /= 10;
  }
  fr (i, (cnt + 1) / 2 ){
    swap(dig[i], dig[cnt - 1 - i]);
  }
  /*
  cout << x << " === \n";
  fr (i, cnt){
    cout << dig[i] << " ";
  }
  cout << endl;
  */
  ll res = f_cnt[cnt - 1];
  if (cnt > 10){
    return pb(res, false);
  }
  res += (fact[9] / fact[10 - cnt]) * (ll)(dig[0] - 1);
  fr (i, cnt - 1){
    if (flg[dig[i]]){
      return pb(res, false);
    } else {
      flg[dig[i]] = true;
      fr (j, dig[i + 1]){
	if (!flg[j]){
	  res += (fact[10 - i - 2] / fact[10 - cnt]);
	}
      }
    }
  }
  if (flg[dig[cnt - 1]]){
    return pb(res, false);
  } else {
    return pb(res, true);
  }
}

int main(){
  int t;
  s(t);
  fact[0] = 1;
  f (i, 1, 10){
    fact[i] = fact[i - 1] * (ll) i;    
  }
  f (i, 10, 20){
    fact[i] = 0;
  }
  f_cnt[0] = 0; f_cnt[1] = 9;
  f (i, 2, 11){
    f_cnt[i] = f_cnt[i - 1] * (11 - i);    
  }

  f (i, 1, 11){
    f_cnt[i] += f_cnt[i - 1];
  }
  f (i, 11, 20){
    f_cnt[i] = f_cnt[i - 1];
  }
  ll a, b;
  ll res;
  while (t--){
    sll(a); sll(b);
    pb a1 = result(a);
    pb a2 = result(b);
    res = a2.first - a1.first + a2.second;
    // cout << a1.first << " " << a2.first << " " << a1.second << " "  << a2.second << endl;
    printf("%lld\n", res);    
  }
  return 0;
}
