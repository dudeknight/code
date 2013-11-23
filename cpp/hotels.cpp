#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

#define get_int(x) scanf("%d",&x)
#define get_ll(x) scanf("%lld",&x)
#define pi pair<long long,int>
#define pic pair< pair<long long,int> ,char>


long long a[1000000];
long long remap[1000000];
long long res[1000000];





int main(){
  long long n;
  get_ll(n);
  long long k;get_ll(k);
  long long sum=0;
  for(int i=0;i<n;i++){
    get_ll(a[i]);
    sum+=a[i];
  }

  for(int i=0;i<n;i++){
    remap[i]=a[i];
  }
  
  long long maxi=0;
  long long count=0;
  int i=0;
  int j=0;
  for(i=0;i<n && count+a[i]<=k;i++){
    count+=a[i];
  }

  maxi=count;
  
  while (1){
    if(count+a[i]>k){
      maxi=max(count,maxi);
      count-=a[j];j++;
    }
    else{
      count+=a[i];i++;
    }
    if(i==n) break;
  }
  maxi=max(count,maxi);
  printf("%lld",maxi);

  printf("\n");
  return 0;

}
