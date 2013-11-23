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


ll a[3][5000];


int main(){
  int t;s(t);
  fr(i,t){
    sll(a[0][i]);
    sll(a[1][i]);
    sll(a[2][i]);
  }
  ll s[3];
  fr(i,3) s[i]=0;

  fr(i,t){
    fr(j,3)
      s[j]+=a[j][i];
  }
  int mini[3];
  ll mini_res=s[0]+s[1]+s[2];
  fr(i,t){
    fr(j,t){
      fr(k,t){
	if(i==j||j==k||k==i) continue;
	ll val=s[0]-a[0][i]+s[1]-a[1][j]+s[2]-a[2][k];
	if(val<mini_res){
	  mini_res=val;
	  mini[0]=i;mini[1]=j;mini[2]=k;
	}
      }
    }
  }
  fr(i,3){
    printf("%d\n",mini[i]);
  }
  return 0;
}
