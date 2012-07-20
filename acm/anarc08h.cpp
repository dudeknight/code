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

#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

ll a[1000001];

int main(){
  ll n,d;
  sll(n);sll(d);
  a[1]=0;
  while(n!=0){
    f(i,2,n+1)
      a[i]=(a[i-1]+d)%i;
    printf("%lld %lld %lld\n",n,d,a[n]+1);
    sll(n);sll(d);
  }

  

}
