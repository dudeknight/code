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

ll sz=2720000;

long double a[2720000];


int main(){
  long double sum=0;
  f(i,2,sz){
    //cout<<i<<endl;
    sum+=log(i+0.00);
    a[i]=sum/(i+0.00);
  }
  int t;
  s(t);
  fr(trt,t){
    ll x;sll(x);
    long double sr=log(x+0.0);
    long double *r=upper_bound(a+2,a+sz,sr);
    x=(ll)(r-a);
    printf("%lld\n",x);
  }
  return 0;
}
