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
  int a[200000];
  int res[200000];
  int n;
  int t;
  s(t);
  while (t--){
    s(n);
    fr (i, n){
      s(a[i]);
    }
    res[n - 1] = n - a[n - 1];
    fr (i, n - 1){
      int tmp = n - 2 - i;
      if (a[i] 

    }
    fr (i, n){
      printf("%d ",res[i]);
    }
    printf("\n");
  }
  return 0;
}
