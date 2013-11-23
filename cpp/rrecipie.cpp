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
ll mod = 10000009;

ll fast_exp(ll n, ll p){
  ll res = 1;
  while(p){
    if (p & 1){
      res = res * n;
    }
    n = n * n;
    p >>= 1;
  }
  return res;
}

int main(){
  int t, n;
  ll res;
  s(t);
  string s;
  int i, j;
  while (t--){
    cin >> s;
    n = s.size();
    i = 0; 
    j = n - 1;
    res = 1;
    while (i < j){
      if (s[i] == '?' && s[j] == '?'){
	res = res * 26;
	res %= mod;
      } else if (s[i] == '?' || s[j] == '?'){
	res %= mod;
      } else if (s[i] == s[j]){
	res %= mod;
      } else {
	res = 0; break;
      }
      i++; j--;
    }
    if (n % 2 == 1 && s[n / 2] == '?'){
	res = res * 26;
	res %= mod;
    }
    printf("%lld\n", res);
  }
  return 0;
}
