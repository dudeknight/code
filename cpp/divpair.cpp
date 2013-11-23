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


int main(){
  int t;
  ll n,m;
  ll res;
  s(t);
  while(t--){
    sll(n);sll(m);
    if(m%2==0){
      ll x=n/m;
      ll y=n%m;
      if(y==0){
	res=x*x*(m/2-1)+x*(x-1);
	
      }
      else if(y>m/2){
	res=x*x+(y-m/2)*(x+1)*(x+1)+(m-y-1)*(x+1)*x;

      }
      else if(y<m/2){
	res=x*(x-1)+y*(x+1)*(x)+(m/2-y-1)*x*x;
      }
      else{
	res=x*x+(m/2-1)*x*(x+1);
      }

    }
    else{
      ll x=n/m;
      ll y=n%m;
      if(y==0){
	res=x*x*(m/2)+(x*(x-1)/2);
	
      }
      else if(y>m/2){
	res=(x*(x-1))/2+(y-m/2)*(x+1)*(x+1)+(m-y-1)*(x+1)*x;

      }
      else if(y<m/2){
	res=(x*(x-1)/2)+y*(x+1)*(x)+((m/2)-y)*x*x;
      }
      else{
	res=(x*(x-1)/2)+(m/2)*x*(x+1);
      }



    }

    printf("%lld\n",res);
  }


  return 0;
}
