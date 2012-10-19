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
#define sll(x) scanf("%I64d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

//long long lim= 86028200;
int x= 1000001;

bool chk[1000001];

int main(){
  int count=1; 
  for(int i=0;i<x;i++){
    chk[i]=true;
  }

  long long m=1000;
  chk[0] = false;
  chk[1] = false;
  for(ll i=2;i <= m;i += 1){
    if(chk[i]) {
      for(ll j = i * i;j <=  x;j += i){
	chk[j]=false;
      }
    }
  }

  int t;scanf("%d",&t);
  while(t--){
    ll x1; cin >> x1;
    ll y = (ll)(sqrt(x1));
    if ( y * y == x1){
      if (chk[y]){
	printf("YES\n");
      } else {
	printf("NO\n");
      }
    } else {
      printf("NO\n");
    }
  }  
  return 0;
}
