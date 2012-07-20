#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


int a[2000],n;
int b[2000],m;
int dp[2000][2000];
int res;
#define get_int(n) scanf("%d",&n)


void solve(){
  if(a[0]==b[0])dp[0][0]=1;
  else dp[0][0]=0;
  for(int i=1;i<m+n-1;i++){
    for(int j=0;j<=i;j++){
      int x=j;
      int y=i-j;
      int temp;
      if(x<n && y<m) {
	if(a[x]==b[y]){
	  if(x>0 && y>0)
	    dp[x][y]=1+dp[x-1][y-1];
	  else
	    dp[x][y]=1;
	}
	else{
	  if(x>0 && y>0){
	    dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
	  }
	  else if(x>0){
	    dp[x][y]=dp[x-1][y];
	  }
	  else if(y>0){
	    dp[x][y]=dp[x][y-1];
	  }
	  else{
	    dp[x][y]=0;
	  }
	}
      }
    }
  }
  
  res=max(res,dp[n-1][m-1]);
}





int main(){
  int t;get_int(t);
  
  while(t--){
    int temp;
    for(int i=0;;i++){
      get_int(temp);
      if(temp==0){n=i;break;}
      a[i]=temp;
    }
    res=0;
    while(1){
      get_int(temp);
      if(temp==0) break;
      b[0]=temp;
      for(int i=1;;i++){
	get_int(temp);
	if(temp==0){m=i;break;}
	b[i]=temp;
      }
      solve();
      /*
      for(int i=0;i<n ; i++)
	cout<<a[i]<<'d';
      cout<<endl;
      for(int i=0;i<m;i++)
	cout<<b[i]<<'d';
      cout<<endl;
      
      for(int i=0;i<n;i++){
	cout<<"dp arr : ";
	for(int j=0;j<m;j++){
	  cout<<dp[i][j]<<" ";
	}
	cout<<endl;
      }
      */

    }

    printf("%d\n",res);

  }
  return 0;
}
