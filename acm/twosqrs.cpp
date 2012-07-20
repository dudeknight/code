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

#define sz 1000001

ll a[sz];
//ll b[sz];

int main(){
  int t,j,k;s(t);
  ll n,m,tmp,z,st;
  fr(i,sz){
    a[i]=i*i;
  }

  while(t--){
    sll(n);
    if(n%4==3){
      printf("No\n");
      continue;
    }
    bool bi=false;
    m=(ll)sqrt(n);
    j=0;k=m;
    while(j<=k){
      tmp=n-a[j]-a[k];
      if(tmp>0)
	j++;
      else if(tmp<0)
	k--;
      else{
	bi=true;
	break;
      }
    }

  
    if(bi)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
