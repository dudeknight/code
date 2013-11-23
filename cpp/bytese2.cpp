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



struct brick{
  int x;
  ll y;
};

bool comp(brick a,brick b){
  if(a.y<b.y) {
    return true;
  }
  else if(a.y==b.y){
    if(a.x<b.x){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

	


brick a[300];
int main(){
  int n,t;s(t);
  while(t--){
    s(n);
    fr(i,2*n){
      sll(a[i].y);
      if(i&1)a[i].x=-1;
      else a[i].x=1;
    }
    sort(a,a+2*n,comp);
    int maxi=0,temp=0;
    fr(i,2*n){
      temp+=a[i].x;
      maxi=max(maxi,temp);
    }
    printf("%d\n",maxi);
  }
  return 0;
}



