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
#define ss(x) scanf("%s",x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
int a[4000][4000];
int dp[4010][4010];
int dp_r[4010][4010];
char c[2];
int m,n;
ll f;


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
    /*
    fr(i,m){
      fr(j,n){
	cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    */
    fr(i,m+1){
      dp[i][0]=0;
      dp_r[i][0]=0;
    }
    fr(i,n+1){
      dp[0][i]=0;
      dp_r[0][i]=0;
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
    f(i,1,n+1){
      f(j,1,m+1){
	if(dp[j][i]==0) dp_r[i+1][j+1]=0;
	else{
	  int mini=dp[j][i];
	  int k=j-1;
	  int temp;
	  glb_max=glb_max>mini?glb_max:mini;
	  for(k=j-1;k>0&&dp[k][i]>0;k--){
	    mini=mini<dp[k][i]?mini:dp[k][i];
	    temp=mini*(j-k+1);
	    glb_max=glb_max>temp?glb_max:temp;	    
	  }
	}
      }
    }
    printf("%lld\n",glb_max*3);

  }
  return 0;
}
