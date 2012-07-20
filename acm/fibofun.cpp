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
  s(t);
  ll a,b,m,n;
  ll x1,x2,x3;
  ll sum,res;
  while(t--){
    sll(a);sll(b);sll(n);sll(m);
    x1=1;
    x2=1;
    sum=2;
    f(i,2,n-1){
      x3=x1+x2;
      sum+=x3;
      x1=x2;
      x2=x3;
      
    }
    if(n==0){
      printf("0\n");
      continue;
    }
    if(n==1){
      printf("%lld\n",a%m);
      continue;
    }
    if(n==2){
      printf("%lld\n",(a+b)%m);
      continue;
    }
	
    
    res=(a*(sum-x2+1))%m+(b*sum)%m;
    res%=m;
    
    printf("%lld\n",res);
    
    

  }
    
  return 0;


}
