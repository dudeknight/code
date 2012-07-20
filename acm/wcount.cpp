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
#define fl(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)
#define mod 1000000007
typedef long long ll;

ll fc[505];
ll invfc[505];

ll fstpw(ll x,ll v){
  ll res=1;
  while(v!=0){
    if(v&1){
      res*=x;
      res%=mod;
    }
    v>>=1;
    x=x*x;
    x%=mod;
   
  }
  return res;

}


void fill(){
  ll res=1;
  fc[0]=1;
  invfc[0]=1;
  fl(i,1,503){
    res*=i;res%=mod;
    fc[i]=res;
    invfc[i]=fstpw(res,mod-2);
  }
  /*
  fr(i,10){
    cout<<fc[i]<<" "<<invfc[i]<<endl;
  }
  */
}

int a[257];
char c[510];
int main(){
  int t;
  int n;
  ll res;
  fill();
  s(t);
  while(t--){
    ss(c);
    
    n=strlen(c);
    res=fc[n];
    fr(i,256){
      a[i]=0;
    }
    f(i,0,n){
      a[c[i]]++;
    }
    
    fr(i,256){
      res*=invfc[a[i]];
      res%=mod;
    }
    printf("%lld\n",res);
  }

  

  return 0;
}
