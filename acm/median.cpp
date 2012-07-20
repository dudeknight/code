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



ll a[50];
ll mx;

int main(){
  int t;
  while(t--){
    int n;
    s(n);
    fr(i,n)
      sll(a[i]);
    
    fr(i,n)
      mx=max(a[i],mx);
    
    fr(i,n){
      if(mx==a[i]){
	
      }
    
    }


  }


}
