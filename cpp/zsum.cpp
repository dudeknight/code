#include <iostream>
#include <cmath>
using namespace std;


#define mod 10000007

long long fastpow(long long n,int k){
	if(k==0) return 1;
	if(k&1){
		long long val=fastpow(n,k>>1);
		long long v=(val*((val*n)%mod))%mod;

		return v;
	}
	else{
		long long val=fastpow(n,k>>1);
		long long v=(val*val)%mod;
		return v;
	}
}

int main(){
	long long n,k;
	cin>>n>>k;
	while(n!=0){
		cout<<(fastpow(n,k)+2*fastpow(n-1,k)+fastpow(n,n)+2*fastpow(n-1,n-1))%mod<<endl;
		cin>>n>>k;
	}
	return 0;
}

