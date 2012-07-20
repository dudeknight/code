//the template by dvdreddy

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <stack>
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
#define clear(x) while(!x.empty()){x.pop();}

typedef long long ll;

int dp[4010];
int lr[4010];
int rl[4010];
int st[4010];
int st_ptr=0;
char c[5000];
int m,n;
ll f;
ll glb_max=0;
ll temp_st=0;

int main(){

  s(m);s(n);
  while(m!=0 && n!=0){
    sll(f); 
    fr(i,n){
      dp[i]=0;
    }
    glb_max=0;
    temp_st=0;
    fr(i,m){
      ss(c);

      fr(j,n){
	if(c[j]=='C') dp[j]=0;
	else dp[j]+=1;
      }

      temp_st=-1;st_ptr=0;
      
      fr(j,n){
	if(dp[j]==0){st_ptr=0;temp_st=j;continue;}
	while(st_ptr!=0 && dp[st[st_ptr]]>=dp[j])
	  st_ptr--;
	if(st_ptr){
	   lr[j]=j-st[st_ptr]-1;
	}
	else{
	  lr[j]=j-temp_st-1;
	}
	st_ptr++;
	st[st_ptr]=j;
      }

      temp_st=n;st_ptr=0;
      for(int j=n-1;j>=0;j--){
	if(dp[j]==0){st_ptr=0;temp_st=j;continue;}
	while(st_ptr!=0 && dp[st[st_ptr]]>=dp[j])
	  st_ptr--;
	if(st_ptr){
	  rl[j]=st[st_ptr]-j-1;
	}
	else{
	  rl[j]=temp_st-j-1;
	}
	st_ptr++;
	st[st_ptr]=j;
      }
      fr(j,n) {
	temp_st=dp[j]*(1+rl[j]+lr[j]);
	glb_max=glb_max>temp_st?glb_max:temp_st;
      }

    }

    printf("%lld\n",glb_max*f);
    s(m);s(n);
  }
  return 0;
}
