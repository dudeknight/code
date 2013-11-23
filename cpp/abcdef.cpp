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

ll a[100];
int sz1=0,sz2=0;
ll imp1[1000000];
ll imp2[1000000];
int n;
int main(){
  int n;
  s(n);
  fr(i,n){
    sll(a[i]);
  }
  fr(i,n){
    fr(j,n){
      fr(k,n){
	imp1[sz1]=a[i]*a[j]+a[k];sz1++;
      }
    }
  }
  sort(imp1,imp1+sz1);
  fr(i,n){
    fr(j,n){
      fr(k,n){
	if(a[i]){
	  imp2[sz2]=a[i]*(a[j]+a[k]);sz2++;
	}
      }
    }
  }
  sort(imp2,imp2+sz2);
  imp2[sz2]=max(imp1[sz1-1],imp2[sz2-1])+1;sz2++;
  ll res=0;
  ll tmp=0;
  ll int1=0,int2=0;
  //code similar for merge
  while(int1<sz1 && int2 < sz2){
    if(imp1[int1]<imp2[int2]){
      if(int1 && imp1[int1]==imp1[int1-1]){res+=tmp;}
      else{tmp=0;}
      int1++;
    }
    else if(imp1[int1]>imp2[int2]){
      int2++;
    }
    else{
      tmp=0;
      while(imp1[int1]==imp2[int2]) {int2++;tmp++;}
      res+=tmp;int1++;
    }
  }
  
  printf("%lld\n",res);
}
