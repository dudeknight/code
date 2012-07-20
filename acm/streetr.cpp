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


ll gcd(ll x,ll y){
  if(x>y) swap(x,y);
  ll temp;
  while(x>0){
    temp=y%x;
    y=x;x=temp;

  }
  return y;
}


ll a[100000];
ll b[100000];


int main(){
  int n;
  s(n);
  fr(i,n)
    sll(a[i]);
  f(i,1,n)
    b[i-1]=a[i]-a[i-1];
  ll g=gcd(b[0],b[1]);
  f(i,2,n-1)
    g=gcd(g,b[i]);
  //printf("%lld\n",g);
  int res= ((a[n-1]-a[0])/g) - n+1;
  printf("%d",res);
}
