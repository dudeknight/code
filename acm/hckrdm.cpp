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


ll a[100000];


int main(){
  int n,k;
  s(n);s(k);
  fr(i,n)
    sll(a[i]);
  sort(a,a+n);
  int i=0;
  int j=1;
  int res=0;
  while (j<n){
    ll diff=a[j]-a[i];
    if(diff<k)
      j++;
    else if(diff>k)
      i++;
    else{
      res++;j++;i++;
    }

  }
  printf("%d\n",res);
}
