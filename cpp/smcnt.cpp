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
#define sl(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
long long a[1000002];
long long res[1000002];
long long b[1000002];
long long mp[1000002];
long long mp_tmp[1000002];
long long n=0;

void merge(ll i,ll j,ll k){
  ll x=i;
  ll y=j;
  ll z=i;
  while(x<j && y<k){
    if(a[x]<=a[y]){
      res[mp[x]]+=y-j;
      mp_tmp[z]=mp[x];
      b[z]=a[x];
      z++;x++;
    }
    else{
      b[z]=a[y];
      mp_tmp[z]=mp[y];
      z++;y++;
    }
  }
  if(x<j){
    while(x<j){
      b[z]=a[x];
      res[mp[x]]+=k-j;
      mp_tmp[z]=mp[x];
      x++;z++;
    }
  }
  if(y<k){
    while(y<k){
      mp_tmp[z]=mp[y];
      b[z]=a[y];
      z++;y++;
    }
  }
  
  f(p,i,k){
    a[p]=b[p];
    mp[p]=mp_tmp[p];
  }
  /*
  cout<<i<<" "<<j<<" "<<k<<endl;
  f(p,i,k)
    cout<<a[p]<<" "; 
  cout<<endl;
  f(p,i,k)
    cout<<res[p]<<" ";
  cout<<endl;
  */
}


void func(){
  ll m=1;
  while(m<n){
    ll i=0;
    while(i<n-m){
      merge(i,i+m,min(i+2*m,n));
      i+=2*m;
    }
    m*=2;
  }
    
}


int main(){

  bool flg=false;
  while(1){
    int t=sl(a[n]);
    res[n]=0;
    mp[n]=n;
    if(t==EOF) break;
    n++;
  }

  func();
  fr(i,n){
    if(i)
      printf(" ");
    printf("%lld",res[i]);
  }
  return 0;
}
  
