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

int  prime[100000];

bool chk[100010];
int a[100010];
int fl[101][25000];
int fh[1400][5000];
int main(){
  //  div.resize(1000001);
  int count=1;
  prime[0]=2;
  //memset(a,1,sizeof(a));
  //memset(chk,true,sizeof(chk));
  
  for(int i=0;i<100001;i++){
    a[i]=1;
    chk[i]=true;
    }
  for(int i=3;i<100001;i+=2){
    if(chk[i]){
      prime[count]=i;count++;
      for(long long j=3*i;j<100001;j+=(2*i)){
	chk[j]=false;
      }
    }
  }

  //return 0;

  //cout<<count<<endl;
  int maxi=0;
  for(int i=0;i<count;i++){
    int k=prime[i];
    for(int j=k;j<100001;j+=k){
      int res=0;int v=j;
      while(v%k==0 && v!=0){
	res++;v/=k;
      }
      a[j]*=(2*res+1);
    }
   
  }
  for(int i=0;i<100;i++){
    fl[i][0]=1;
  }
  for(int i=100;i<1400;i++){
    fh[i][0]=1;
  }
  

  for(int i=1;i<100001;i++){

    assert(a[i]%2!=0);
    int x=a[i];
    if(x<100){
      fl[x][fl[x][0]]=i;
      fl[x][0]++;
    }
    else{
      fh[x][fh[x][0]]=i;
      fh[x][0]++;
    }
  }
  //cout<<"m --- "<<maxi<<endl;
  //return 0;



  int t;scanf("%d",&t);
  long long lo,hi;int k;
  while(t--){
    scanf("%d %lld %lld\n",&k,&lo,&hi);
    if(k>1323) {printf("0\n");continue;}
    long long mlo=ceil(sqrt(lo));
    long long mhi=floor(sqrt(hi));    
    int res=0;int *lo,*hi,*beg,*end;
    if(k<100){
      beg=fl[k]+1;
      end=fl[k]+fl[k][0];
    }
    else{
      beg=fh[k]+1;
      end=fh[k]+fh[k][0];
    }
    //cout<<beg<<" "<<end<<endl;
    lo=lower_bound(beg,end,mlo);
    hi=upper_bound(beg,end,mhi);
    res=hi-lo;
    printf("%d\n",res);
  }
  
  return 0;


}
