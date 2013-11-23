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

ll x1[10002];
ll x2[10002];

int main(){
  int t;
  s(t);
  x1[0]=0;
  x2[0]=2;
  f(i,1,10002){
    if(i&1){
      x1[i]=x1[i-1]+1;
      x2[i]=x2[i-1]+1;
    }
    else{
      x1[i]=x1[i-1]+3;
      x2[i]=x2[i-1]+3;
    }

  }

  while(t--){
    int a,b;
    s(a);s(b);
    if(a==b){
      printf("%lld\n",x1[a]);
    }
    else if(b+2==a){
      printf("%lld\n",x2[b]);
    }
    else{
      printf("No Number\n");
    }
  }

  return 0;
}
