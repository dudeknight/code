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

char c[250];

struct brick{
  int x;
  ll y;
};

bool comp(brick a,brick b){
  if(a.y<b.y) {
    return true;
  }
  else if(a.y==b.y){
    if(a.x>=b.x){
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

	


brick a[1200];

int main(){
  int n,t=10;
  ll p,k;
  while(t--){
    ss(c);
    sll(p);sll(k);
    s(n);
    fr(i,2*n){
      sll(a[i].y);
      if(i&1)a[i].x=-1;
      else a[i].x=1;
    }
    sort(a,a+2*n,comp);
    int maxi=0,temp=0;
    int mini=n;
    bool flag=false;
    fr(i,2*n){
      if(a[i].y>k ||( a[i].x==-1 && a[i].y==k)){
	flag=false;
	mini=min(mini,temp);
	maxi=max(maxi,temp);
	break;
      }
      if(a[i].y==p && ){
	flag=true;
	mini=min(mini,temp);
	maxi=max(maxi,temp);
      }

      temp+=a[i].x;
      //      cout<<a[i].y<<" "<<temp<<endl;
      if(flag){
	mini=min(mini,temp);
	maxi=max(maxi,temp);
	continue;
      }
      if(a[i].y>=p){
	flag=true;
	mini=min(mini,temp);
	maxi=max(maxi,temp);
      }
    }
    printf("%d %d\n",mini,maxi);
    ss(c);ss(c);ss(c);
  }
  return 0;
}



