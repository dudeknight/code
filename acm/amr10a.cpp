#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;


double a[500001];

long long x[500001];
long long y[500001];
int  n,q;
int main(){
  scanf("%d %d",&n,&q);
  scanf("%lld %lld",&x[0],&y[0]);
  scanf("%lld %lld",&x[1],&y[1]);
  a[0]=(double)(y[0]+y[1])*(x[1]-x[0])/2.00;
  double tot=0;
  for(int i=2;i<n;i++){
    scanf("%lld %lld",&x[i],&y[i]);
    a[i-1]=a[i-2]+(double)(y[i]+y[i-1])*(x[i]-x[i-1])/2.00;
  }
  a[n-1]=a[n-2]+(double)(y[0]+y[n-1])*(x[0]-x[n-1])/2.00;
  tot=a[n-1];
  double res;int a1,b1,temp;
  //printf("%.1f \n",tot);  
  for(int i=0;i<q;i++){
    scanf("%d %d",&a1,&b1);
    if(a1) res=a[b1]-a[a1-1];
    else res=a[b1];
    res+=(double)(y[a1]+y[b1])*(x[a1]-x[b1])/2.00;
    res=res>tot-res?tot-res:res;
    printf("%.1f \n",res);
  }
  return 0;
}


