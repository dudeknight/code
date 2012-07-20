#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define get_ll(x) scanf("%lld",&x)
#define get_int(x) scanf("%d",&x)

long long a[100100];
long long b[100100];

int main(){
  int t;get_int(t);
  while(t--){
    long long n;get_ll(n);
    for(int i=0;i<n;i++){
      get_ll(a[i]);
    }

    
    sort(a,a+n);
    if(n==2 && a[0]==2 &&a[1]==3){
      printf("2 3\n");
      continue;
    }
    
    long long c=0;
    while(a[c]==1 && c< n) c++;
    
   

    for(int i=0;i<c;i++)b[i]=a[i];
    if(n-c==2 && a[n-1]==3 &&a[n-2]==2){
      b[n-1]=3;b[n-2]=2;
    }
    else{
      for(int i=0;i<n-c;i++){
	b[n-1-i]=a[c+i];
      }
    }
    
    for(int i=0;i<n;i++){
      printf("%lld ",b[i]);
    }
    printf("\n");

  }
  return 0;
}


