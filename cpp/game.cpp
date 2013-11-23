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


double a[1000000];


int main(){
  double p;

  scanf("%lf",&p);
  a[0]=p;

  int q;
  s(q);
  f(i,1,1000000){
    a[i]=(a[i-1]*(1-p))+(1-a[i-1])*p;
  }
  ll t;

  fr(i,q){
    sll(t);

    printf("%.4lf\n",a[t-1]);
    
  }

  return 0;
}
