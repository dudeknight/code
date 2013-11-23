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

#define size 20000

ll a[size];
ll m[size];
ll bin[size];
ll p[size];
ll cnt[size];


int l;
int main(){
  int n;

  s(n);
  fr(i,n){
    sll(a[i]);
  }
  
  m[0]=0;
  bin[0]=a[0];
  cnt[0]=1;
  p[0]=-1;//does not exist
  l=1;//length of longest increasing subseq
  ll* x;
  f(i,1,n){
    x=lower_bound(bin,bin+l,a[i]);
    int j=(int)(x-bin);
    cout<<j<<endl;
   
    
    if(j!=0){
      cnt[i]=cnt[m[j-1]]+1;
      p[i]=m[j-1];
    }
    else{
      cnt[i]=1;
      p[i]=-1;
    }
    if(j==l || a[i]<a[m[j]]){
      m[j]=i;
      bin[j]=a[i];
      l=max(l,j+1);
    }
  }
  
  
  fr(i,n){
    cout<<cnt[i]<<" ";
  }
  cout<<endl<<l<<endl;
  




  return 0;
}
