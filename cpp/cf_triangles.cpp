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
#define sll(x) scanf("%l64d", &x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  ll n;int m;
  int tempn;
  s(tempn); s(m);
  n = (ll) tempn;
  ll a[1000001];
  fr (i, n + 1){
    a[i] = 0;
  }
  if (n == 1 || n == 2){
    cout << 0 << endl;
    return 0;
  }
  
  ll x = (n * (n - 1) * (n - 2)) / 6;

  fr (i, m){
    int tempx;
    s(tempx); a[tempx]++;
    s(tempx); a[tempx]++;
  }
  ll tempx = 0;
  fr (i, n + 1){
    tempx += (n - 1 - a[i]) * a[i];
  }
  tempx /= 2;
  cout << x - tempx << endl;
  return 0;
}
