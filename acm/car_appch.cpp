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

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


struct intv{
  double a;
  double b;
};

int n;
intv a[100];
int perm[100];

bool valid(double val){
  fr (i, n){
    perm[i] = i;
  }
  do {
    double x = a[perm[0]].a;
    bool b = true;
    f (i, 1, n){
      double y = x + val;
      intv bx = a[perm[i]];
      if (bx.b < y){
	b = false;
	break;
      } else {
	y = max(y, bx.a);
      }
      x = y;
    }
    if (b) {
      return true;
    }
  } while (next_permutation(perm, perm + n));
 
  return false;
}

int main(){
  si(n);
  int caset = 1;
  while (n){
    double hi = 0;
    double lo = 1;
    fr (i, n){
      int x;
      si(x); a[i].a = x * 60.0;
      si(x); a[i].b = x * 60.0;
      hi = max(hi, a[i].b);
    }
    while (hi - lo > 0.0000001 && hi > 0){
      double mid = (lo + hi) / 2;      
      if (valid(mid)){
	lo = mid;
      } else {
	hi = mid;
      }
    }
    
    int mts = ((int) hi) / 60;
    int sec = ((int) hi) % 60;
    printf("Case %d: %d:%02d\n", caset, mts, sec);
    si(n);
    caset++;
  }

  return 0;
}
