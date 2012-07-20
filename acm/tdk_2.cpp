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

long long lim= 86028200;
long long q_lim= 5001000;

long long *prime;
bool *chk;
int main(){
  prime=new long long[q_lim];
  chk=new bool[lim];
  int count=1;

	//return 0;
  prime[0]=2;

  
  for(long long i=0;i<lim;i++){
    chk[i]=true;
  }
  //return 0;
  long long m=sqrt(lim);
  long long x=lim/2;
  for(long long i=3;i<=m;i+=2){
    if(chk[i]){
      for(long long j=i*i;j<lim;j+=(2*i)){
	chk[j]=false;
      }
    }
  }

  for(long long i=3;i<lim && count<q_lim;i+=2){
    if(chk[i]){prime[count]=i;count++;}
  }

  int t;scanf("%d",&t);
  long long lo;
  while(t--){
    scanf("%lld",&lo);
    printf("%lld\n",prime[lo-1]);
  }
  
  return 0;


}

