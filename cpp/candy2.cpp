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
  ll maxi[3][3];
  fr(i,t){
    fr(j,3)
      s[j]+=a[j][i];
  }
  fr(k,3){
    fr(i,3)
      maxi[k][i]=-1;
    fr(i,t){
      if(a[k][maxi[k][0]]<=a[k][i]){
	maxi[k][2]=maxi[k][1];
	maxi[k][1]=maxi[k][0];
	maxi[k][0]=i;
	
      }
      else if(a[k][maxi[k][1]]<=a[k][i]){
	maxi[k][2]=maxi[k][1];
	maxi[k][1]=i;
	
      }
      else if(a[k][maxi[k][2]]<=a[k][i]){
	maxi[k][2]=i;
      }
    }
    
  }
  int mini[3];ll mini_res=s[0]+s[2]+s[1];
  fr(xi,3){
    fr(xj,3){
      fr(xk,3){
	int i=maxi[0][xi];int j=maxi[1][xj];int k=maxi[2][xk];
	if(i==j || j==k||k==i) continue;
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
