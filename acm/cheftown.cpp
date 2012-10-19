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

#define size 400000
int a[size];

int main(){
  int n, w;
  s(n); s(w);
  map<int, char> m;
  fr (i, n){
    s(a[i]);
  }
  
  int res = 0;
  fr (i, w){
    m[a[i]] = '0';
  }
  map<int, char>::iterator it, jt;
  f (i, 1, n - w + 1){
    it = m.begin();
    jt = m.end(); jt--;
    if ((jt->first - it->first) == w - 1){
      res++;
    }
    it = m.find(a[i - 1]);
    m.erase(it);
    m[a[i + w - 1]] = '0';
  }

  it = m.begin();
  jt = m.end(); jt--;
  if ((jt->first - it->first) == w - 1){
    res++;
  }
  printf("%d\n", res);

  return 0;
}
