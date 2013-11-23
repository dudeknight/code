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

ll a[100][100];
ll b[100][100];

int main(){
  int t, m, n;
  s(t);
  ll res, c, rmax;
  while (t--){
    s(m); s(n);
    res = 0;
    fr (i, m){
      fr (j, n){
	sll(a[i][j]);
      }
    }
    fr (i, m){
      fr (j, n){
	sll(b[i][j]);
      }
    }
    
    fr (i, m){
      rmax = 0;
      fr (j, n){
	sll(c);
	rmax = max(rmax, c * min(a[i][j], b[i][j]));
      }
      res += rmax;
    }

    printf("%lld\n", res);
  }
  return 0;
}
