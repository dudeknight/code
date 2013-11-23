#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

#define get(x) scanf("%lld",&x)

#define MAX 10000000000

long long a[502];
long long sum[505];
long long dp[502][502];
long long n,k;
int main(){
  long long t;get(t);
  while(t--) {
    
    get(n);get(k);
    //cout<<n<<" "<<k<<endl;
    sum[0]=0;

    for (int i=0;i<n;i++){
      get(a[i]);      
      sum[i+1]=sum[i]+a[i];

    }

    for(int i=0;i<n;i++){
      for(int j=0;j<k;j++){
	dp[i][j]=MAX;
      }
    }
    for(int i=n-1;i>=0;i--){
      dp[i][k-1]=sum[n]-sum[i];
    }

    for(int i=k-2;i>-1;i--) {
      for(int j=n-k+i;j>-1;j--){
	for(int p=j+1;p<n;p++){
	//code for dp[i][j]
	  if(dp[j][i]>max(sum[p]-sum[j],dp[p][i+1])){
	    dp[j][i]=max(sum[p]-sum[j],dp[p][i+1]);
	  }
	}
      }      
    }


    
    long long max_val=dp[0][0];
    string s="";
    char tmp[50];
    bool flag =false;
    long long cur=0;
    long long cust=0;
    for(int i=n-1;i>=0;i--){
      if(flag){
	sprintf(tmp,"%lld",a[i]);
	if(i)s=" / "+string(tmp)+s;
	else s=" "+string(tmp)+s;
	continue;
      }
      if(i+1-k+cust==-1){
	s=" /"+s;flag=true;i++;
      }
      else if(cur+a[i] > max_val){
	s=" /"+s;cust++;cur=0;i++;
      }
      else{
	sprintf(tmp,"%lld",a[i]);
	s=" "+string(tmp)+s;
	cur+=a[i];
      }
      
    }
    cout<<s.substr(1,s.size()-1)<<endl;
 } 
    


  return 0;
}
