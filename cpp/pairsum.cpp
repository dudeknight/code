#include <iostream>
#include <cstdio>
using namespace std;

#define ull unsigned long long

#define get(x) scanf("%lld",&x)

ull a[100002];
ull sum1[100002];
ull sum2[100002];


int main(){
  ull n;get(n);a[0]=0;sum1[0]=0;sum2[0]=0;
  for(int i=1;i<n+1;i++){
    get(a[i]);
    sum1[i]=sum1[i-1]+a[i];
    sum2[i]=sum2[i-1]+a[i]*sum1[i];
  }
  /*
  for(int i=0;i<n+1;i++){
    cout<<sum1[i]<<" ";
  }
  cout<<endl;
  
  for(int i=0;i<n+1;i++){
    cout<<sum2[i]<<" ";
  }
  cout<<endl;
  */
  ull m,u,v;get(m);
  while(m--){
    get(u);get(v);
    printf("%lld\n",sum2[v+1]-sum2[u]-(sum1[v+1]-sum1[u])*(sum1[u]));
 
  }

  return 0;
}
  

