#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];


int main(){
  int t;
  cin>>t;
  int ct=1;
  while(t--){
    int n;int res;
    scanf("%d %d",&res,&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int ans=0;
    for(int i=n-1;i>=0;i--){
      if(res<=0)break;
      else{ans++;res-=a[i];}
    }
    if(res<=0)
      printf("Scenario #%d:\n%d\n\n",ct,ans);
    else
      printf("Scenario #%d:\nimpossible\n\n",ct,ans);

    ct++;
  }
  return 0;
}
