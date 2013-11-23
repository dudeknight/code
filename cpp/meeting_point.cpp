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
#define size 100000

ll a[size];
ll b[size];

int main(){
  int n;
  s(n);
  ll x, y;
  fr (i, n){
    sll(x); sll(y);
    a[i] = x + y;
    b[i] = x - y;
  }

  ll res = 0;
  sort(a, a + n);
  sort(b, b + n);
  
  x = a[n / 2];
  y = b[n / 2];
  fr (i, n){
    res += abs(a[i] - x) + abs(b[i] - y);
  }
  res /= 2;
  printf("%lld\n", res);
  return 0;
}
