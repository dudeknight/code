#include <iostream>
#include <cstdio>
using namespace std;

#define get_int(x) scanf("%lld",&x);

unsigned long long  a[1000001];

unsigned long long f(unsigned long long  n){
  return (n*(n+1)*(n+2))/6;
}


int main(){
  a[1]=0;a[2]=1;
  for(unsigned long long i=3;i<1000001;i++)
    a[i]=a[i-2]+(i-1)*i/2;
  int t;unsigned long long n;
  get_int(t);
  while(t--){
    cin>>n;
    printf("%lld\n",f(n)+a[n]);
     
  }
  return 0;
}
