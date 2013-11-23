#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <assert.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;



bool chk[1000100];
int prime[1000100];

int main(){

  //int count=1;
  //prime[0]=2;

  
  for(int i=4;i<1000001;i+=2){
    //a[i]=i;
    chk[i]=false;
  }
  for(int i=3;i<1000001;i+=2)
    chk[i]=true;
  
  //a[1]=1;
  chk[1]=false;
  
  for(int i=3;i<1000001;i+=2){
    if(chk[i]){
      //prime[count]=i;count++;
      for(long long j=3*i;j<1000001;j+=2*i){
	chk[j]=false;
      }
    }
  }
  
  //return 0;
  /*
  for(int i=2;i<1000001;i++){
    for(int j=2*i;j<1000001;j+=i){
      a[j]-=a[i];
    }
  }
  */
  
  

  //return 0;
  
  int t;scanf("%d",&t);
  long long lo,hi;int k;
  while(t--){
    scanf("%d\n",&k);
    int res=k%2==0?k/2:k;
    int tmp=k;
    int m=sqrt(k);
    while(k%2==0) k/=2;
    for(int i=1;i<=m;i+=2){
      if(k%i==0){
	int j=k/i;
	if(chk[i]) res=res*(i-1)/i;
	if(chk[j]) {res=res*(j-1)/j;}
      }
    }
    if(chk[m]&& m*m==tmp){res=res*m/(m-1);}
    //cout<<endl;
    printf("%d\n",res);
  }
  
  return 0;


}
