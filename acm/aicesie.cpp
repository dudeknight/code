#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

bool chk[200000];

int a[1000001];


int main(){
  for(int i=2;i<=100001;i++) {chk[i]=true;}
  a[2]=1;
  for(int i=3;i<=1;i++){
    int m=sqrt(i);
    int res=0;
    for(int j=2;j<=m;j++){
      if(i%j==0){
	if(chk[j]){chk[j]=false;res++;}
	if(chk[i/j]){chk[i/j]=false;res++;}
      }
    }
    
    a[i]=a[i-1]-res+1;
  }
  //return 0;
  int t,n,p;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",n-n/2);
  }

  return 0;
}
