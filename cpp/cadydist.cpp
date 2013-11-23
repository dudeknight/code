#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define get_int(x) scanf("%d",&x)
#define get_ll(x) scanf("%lld",&x)


long long n;
long long a[100000];
long long b[100000];;
int main(){
  get_ll(n);
  while (n){
    for(int i=0;i<n;i++){
      get_ll(a[i]);
    }
    for(int i=0;i<n;i++){
      get_ll(b[i]);
    }    
    sort(a,a+n);
    sort(b,b+n);
    long long res=0;
    for(int i=0;i<n;i++){
      res+=a[i]*b[n-1-i];
    }
    printf("%lld\n",res);
    get_ll(n);
  }


  return 0;
}
