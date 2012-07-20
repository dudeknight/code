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

ll b[3];

int main(){
  b[0]=0;b[1]=0;b[2]=0;
  ll n;
  sll(n);string s;
  fr(i,n){
    cin>>s;
    if(s=="1/4")
      b[0]++;
    else if(s=="1/2")
      b[1]++;
    else
      b[2]++;
  }
  cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
  ll res=1;
  ll tmp=min(b[2],b[0]);
  res+=tmp;b[2]-=tmp;b[0]-=tmp;

  res+=b[1]/2;b[1]%=2;

  b[0]+=b[1]*2;

  res+=b[0]/4;b[0]%=4;

  res+=ceil(b[0]/4.0)+b[2];
  cout<<res<<endl;
  return 0;


}
  
