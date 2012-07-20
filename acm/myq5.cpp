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


ll a[1002][1002];


#define mod 1000000007


int main(){

  fr(i,1002){
    fr(j,1002){
      a[i][j]=0;
    }
  }
  /*
  fr(i,1002){
    a[0][i]=1;
  }
  */

  f(i,1,1001){
    a[i][i]=1;
    for(int j=i-1;j>0;j--){
      a[i][j]=a[i-j][j]+a[i][j+1];
      a[i][j]%=mod;
    }


  }

  /*
  f(i,1,7){
    f(j,1,i+1){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  */

  int t,n,k;s(t);
  while(t--){
    s(n);s(k);
    printf("%lld\n",a[n][k]);
  }
  
}
