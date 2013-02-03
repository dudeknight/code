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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

struct song{
  int tm;
  double prob;
};

song a[50000];

bool comp(song x, song y){
  double xt = (1 - y.prob) * x.prob * x.tm;
  double yt = (1 - x.prob) * y.prob * y.tm;
  if (xt > yt){
    return true;
  } else {
    return false;
  }
}

int main(){
  int n;
  si(n);
  fr (i, n){
    si(a[i].tm); int tmp; si(tmp);
    a[i].prob = ((double)tmp) / (100.00);
  }
  
  sort(a, a + n, comp);

  double curp = 0.0;
  double resd = 0;
  fr (i, n){
    resd += a[i].tm;
    resd += (1 - a[i].prob) * curp;
    curp += (a[i].prob) * a[i].tm;
  }

  printf("%.12lf\n", resd);    
  return 0;
}
