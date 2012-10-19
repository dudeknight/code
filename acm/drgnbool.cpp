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


int main(){
  int a[101];

  int i1[101];int i2[101]; int i3[101];  
  int t;
  s(t);
  int res;
  while (t--){
    fr (i, 101){
      a[i] = 0;
    }
    res = 0;
    int n, m;
    s(n); s(m);
    int p, q;
    fr (i, n){
      s(p); s(q);
      a[q] -= p;
    }
    fr (i, m){
      s(p); s(q);
      a[q] += p;
    }
    fr (i, 101){
      if (a[i] > 0){
	res += a[i];
      }
    }
    printf("%d\n", res);
  }

  return 0;
}
