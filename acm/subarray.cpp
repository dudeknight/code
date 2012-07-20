#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

#define get_int(x) scanf("%d",&x)
#define get_ll(x) scanf("%lld",&x)
#define pi pair<long long,int>
#define pic pair< pair<long long,int> ,char>


long long a[1000000];
long long remap[1000000];
long long res[1000000];


map<pi,int> m;


int main(){
  long long n;
  get_ll(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    get_ll(a[i]);
    sum+=a[i];
  }
  for(int i=0;i<n;i++){
    remap[i]=sum-a[i];
  }
  
  
  long long k;get_ll(k);
  
  long long count=0;
  for(int i=0;i<k;i++){
    m[pi(remap[i],i)]='0';
  }
  res[count]=m.begin()->first.first;count++;
  for(int i=k;i<n;i++){
    m.erase(pi(remap[i-k],i-k));
    m[pi(remap[i],i)]='0';
    res[count]=m.begin()->first.first;count++;
  }

  for(int i=0;i<count;i++){
    if(i) printf(" ");
    printf("%lld",sum-res[i]);
  }
  printf("\n");
  return 0;

}
