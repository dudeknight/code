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

ll a[10001];

int main(){
  for(ll i=1;i<=10000;i++){
    a[i]=i;
  }
  for(ll i=2;i<=5000;i++){
    if(a[i]==i){
      a[i]=i-1;
	for(ll j=2;j<=(10000/i);j++){
	  a[i*j]*=(i-1);
	  a[i*j]/=i;
	}
    }
  }

  //return 0;
  int t,n;s(t);
  while(t--){
    s(n);
    printf("%lld\n",a[n]);
  }
  return 0;
}
