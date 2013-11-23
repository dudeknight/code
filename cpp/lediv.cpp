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


int gcd(int x, int y){
  if (x == 1){
    return 1;
  }
  if (x > y){
    return gcd(y, x);
  } else if (y % x == 0){
    return x;
  } else {
    return gcd(y % x, x);
  }
}

int max_size = 100010;

int prime[100010];

void init(){
  fr (i, max_size){
    prime[i] = i;
  }
  prime[1] = -1;

  f (i, 2, max_size){
    if (prime[i] == i){
      for (ll j = (ll) i * i; j < (ll) max_size; j += (ll) i){
	if (prime[(int)j] == (int)j){
	  prime[(int)j] = (int)i;
	}
      }
    }
  }

}

int main(){
  int t;
  init();
  s(t); int n; int tmp; int res;
  int res_int;
  while (t--){
    s(n); s(tmp); res = tmp;
    fr (i, n - 1){
      s(tmp); res = gcd(res, tmp);
    }
    res_int = prime[res];
    printf("%d\n", res_int);
  }
}
