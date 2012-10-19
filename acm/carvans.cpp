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
  int t, n, res;
  s(t);
  ll a[100000];
  ll b[100000];
  while(t--){
    s(n);
    fr (i, n){
      sll(a[i]);
    }
    
    b[0] = a[0];
    f (i, 1, n){
      b[i] = min(a[i], b[i - 1]);
    }
    res = 0;
    fr (i, n){
      if (b[i] == a[i]){
	res++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
