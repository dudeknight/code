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
int a[4000][4000];
int dp[4010][4010];
int lr[4010];
int rl[4010];
char c[4];
int m,n;
ll f;
stack<int> st;

int main(){
  int t;
  s(t);
  while(t--){
    s(m);s(n);
    fr(i,m){
      fr(j,n){
	ss(c);
	if(c[0]=='R') a[i][j]=0;
	else a[i][j]=1;

      }
    }
    fr(i,m+1){
      dp[i][0]=0;
    }
    fr(i,n+1){
      dp[0][i]=0;
    }
    fr(i,n){
       fr(j,m){
	 if(a[j][i]==1){
	   dp[j+1][i+1]=dp[j+1][i]+1;
	 }
	 else 
	   dp[j+1][i+1]=0;
       }
    }
    ll glb_max=0;
    ll temp_st=0;
    f(i,1,n+1){
      clear(st);
      temp_st=0;
      f(j,1,m+1){
	if(dp[j][i]==0){clear(st);temp_st=j; continue;}

	while(!st.empty() && dp[st.top()][i]>=dp[j][i]){
	  st.pop();
	}
	
	if(st.empty()){
	    lr[j]=j-temp_st-1;
	}
	else{
	  lr[j]=j-st.top()-1;
	}
	st.push(j);
	
      }
      clear(st);
      temp_st=m+1;
      for(int j=m;j>0;j--){
	if(dp[j][i]==0){clear(st);temp_st=j;continue;}
	  
	while(!st.empty() && dp[st.top()][i]>=dp[j][i]){
	  st.pop();
	}
	if(st.empty()){
	    rl[j]=temp_st-j-1;
	}
	else{
	  rl[j]=st.top()-j-1;
	}
	st.push(j);
      }
    
    
      f(j,1,m+1) {
	temp_st=dp[j][i]*(1+rl[j]+lr[j]);
	glb_max=glb_max>temp_st?glb_max:temp_st;

      }
      
    }

    printf("%lld\n",glb_max*3);

  }
  return 0;
}

 
