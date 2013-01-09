// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
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
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define rfr(i,n) rf(i,n-1,0)
typedef long long ll;


int main(){
  int t;
  si(t);
  int w[1000];
  while (t--){
    int n; si(n);
    fr (i, n){
      si(w[i]);
    }
    sort(w, w + n);
    int res = 0;
    rf(i, n - 1, 0){
      res += w[i] - w[0];
    }
    printf("%d\n", res);
  }
  return 0;
}
