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


ll a,b,c;

int main(){
  int t;s(t);
  while(t--){
    sll(a);c=0;
    fr(i,a){
      sll(b);
      c+=b;c%=a;
    }
    if(c) printf("NO\n");
    else printf("YES\n");
    
  }
  return 0;
}
