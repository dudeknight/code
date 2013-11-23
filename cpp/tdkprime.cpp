#include <iostream>
#include <math.h>
#include <cstdio>
#include <assert.h>
using namespace std;

//long long lim= 86028200;
long long q_lim= 5001000;
long long x= 42014104;

long long *prime;
bool *chk;
int main(){



  prime=new long long[q_lim];
  chk=new bool[x];
  int count=1;
  //return 0;
  
  prime[0]=2;

  
  for(int i=0;i<x;i++){
    chk[i]=true;
  }
  //return 0;
  long long m=14700;

  for(int i=2;i<=m;i+=1){
    if(chk[i]) {
      for(long long j=(2*i*(i-1))+1;j<=x;j+=(2*i-1)){
	chk[j]=false;
      }
    }
  }
  //return 0;
  for(int i=2;i<=x && count<=_lim;i+=1){
    if(chk[i]){prime[count]=i;count++;}
  }
  /*
  for(int i=0;i<20;i++){
    cout<<prime[i]<<endl;
  }
  */

  int t;scanf("%d",&t);
  int lo;
  while(t--){
    scanf("%d",&lo);
    if(lo-1)
      printf("%lld\n",2*prime[lo-1]-1);
    else
      printf("2\n");
  }
  
  return 0;


}
