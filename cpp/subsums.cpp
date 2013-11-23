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

ll res,a,b,n;
ll arr[40];
ll sub1[200000];
ll sub2[200000];
ll len1;
ll len2;


int main(){
  sll(n);sll(a);sll(b);
  fr(i,n)
    sll(arr[i]);
  len1=1;
  len2=1;
  sub1[0]=0;
  sub2[0]=0;
  int hn=n/2;
  fr(i,hn){
    ll tmp=len1;
    for(ll j=0;j<tmp;j++){
      sub1[len1]=sub1[j]+arr[i];
      len1++;
    }
  }
  f(i,hn,n){
    ll tmp=len2;
    for(ll j=0;j<tmp;j++){
      sub2[len2]=sub2[j]+arr[i];
      len2++;
    }
  }
  
  res=0;
  sort(sub2,sub2+len2);

  fr(i,len1){
    ll lb=a-sub1[i];
    ll hb=b-sub1[i];
    ll *lower_b=lower_bound(sub2,sub2+len2,lb);
    ll *higher_b=upper_bound(sub2,sub2+len2,hb);
    
    res+=(higher_b-lower_b);
  }

  printf("%lld\n",res);
    
  return 0;
}
