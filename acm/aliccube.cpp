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


ll all_mov[100000];
int mapper[100000];
int cb1[]={1,2,10,9,5,6,14,13};

int cb2[]={3,4,12,11,7,8,16,15};


int init[33];


int main(){
  int cur=0;
  f(i,1,5){
    init[cur]=(1<<(cb1[i-1]-1))+(1<<(cb1[i%4]-1));
    cur++;
    init[cur]=(1<<(cb2[i-1]-1))+(1<<(cb2[i%4]-1));
    cur++;
  }
  f(i,5,9){
    init[cur]=(1<<(cb1[i-1]-1))+(1<<(cb1[(i%4)+4]-1));
    cur++;
    init[cur]=(1<<(cb2[i-1]-1))+(1<<(cb2[(i%4)+4]-1));
    cur++;
  }
  fr(i,4){
    init[cur]=(1<<(cb1[i]-1))+(1<<(cb1[i+4]-1));
    cur++;
    init[cur]=(1<<(cb2[i]-1))+(1<<(cb2[i+4]-1));
    cur++;
  }
  
  fr(i,8){
    init[cur]=(1<<(cb1[i]-1))+(1<<(cb2[i]-1));
    cur++;
  }
  int len_am=0;
  for(int i=0;i<cur;i++){
    all_mov[i]=init[i];
    len_am++;
  }
  fr(i,cur){
    fr(j,cur){
      all_mov[len_am]=init[i]^init[j];
      len_am++;
    }
  }
  int tmp=len_am;
  f(i,32,tmp){
    fr(j,cur){
      all_mov[len_am]=all_mov[i]^init[j];
      len_am++;
    }
  }

  int res=1<<8;res--;
  fr(i,65600)
    mapper[i]=10;
  mapper[res]=0;
  fr(i,32)
    mapper[res^all_mov[i]]=1;
  f(i,32,tmp)
    mapper[res^all_mov[i]]=min(mapper[res^all_mov[i]],2);
  f(i,tmp,len_am)
    mapper[res^all_mov[i]]=min(mapper[res^all_mov[i]],3);
  //return 0;
  //  cout<<cur<<" "<<tmp<<" "<<len_am;
  int t;s(t);
  int cs=1;

  while(t--){
    printf("Case #%d: ",cs);
    ll inp=0;
    int arb;
    int ct=0;
    fr(i,16){
      s(arb);
      if(i<8 && arb ==1 )ct++;
      inp=inp*2+arb;
    }
    if(mapper[inp]<4)
      printf("%d\n",mapper[inp]);
    else printf("more\n");
    cs++;
  }
  return 0;
}
