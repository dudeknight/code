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
  int t;
  int a[100];
  s(t);
  while (t--){
    int n, x;
    s(n); s(x);
    int tot = 0;
    fr (i, n){
      s(a[i]);
      tot += a[i];
    }
    int val = tot / x;
    bool pos = true;
    fr (i, n){
      if (val == (tot - a[i]) / x){
	pos = false;
	break;
      }
    }
    if (pos){
      printf("%d\n", val);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
