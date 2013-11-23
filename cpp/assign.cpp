#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int count_bits(int i){
    unsigned int M1     =   0x55555555 ;
    unsigned int M2     =   0x33333333 ;
    unsigned int M4     =   0x0f0f0f0f ;
    unsigned int M8     =   0x00ff00ff ;
    unsigned int M16    =   0x0000ffff ;
    i   =   ( i & M1   )   +   ( i>>1 & M1   ) ;
    i   =   ( i & M2   )   +   ( i>>2 & M2   ) ;
    i   =   ( i & M4   )   +   ( i>>4 & M4   ) ;
    i   =   ( i & M8   )   +   ( i>>8 & M8   ) ;
    i   =   ( i & M16  )   +   ( i>>16 & M16 ) ;
    return   i ;
}

long long dp[1<<20];

int arr[100][100];

int main(){
	int t;cin>>t;
	while(t){
		int n;cin>>n;
		//cout<<count_bits(n)<<endl;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){	
				cin>>arr[i][j];
			//	cout<<arr[i][j]<<" ";
			}
			//cout<<endl;
		}
		dp[(1<<n)-1]=1;

		for(long i=(1<<n)-2;i>=0;i--){
			long long  res=0;
			int k=count_bits(i);
			for(int j=0;j<n;j++){
				//cout<<arr[k][j]<<" "<<(i&(1<<j))<<endl;
				if(arr[k][j]==1 && (i&(1<<j))==0){
					//cout<<"dbg"<<endl;
					res+=dp[i|(1<<j)];
				}
			}
			//cout<<res<<endl;
			dp[i]=res;
		}
		cout<<dp[0]<<endl;
		t--;	

	}

	return 0;
}
