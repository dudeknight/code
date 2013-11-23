#include <iostream>
#include <math.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t>0){
		int n;cin>>n;
		double m=sqrt(n);
		int r=floor(m);
		long long sum=1;
		for(int i=2;i<=r;i++){
			if(n%i==0) sum+=(i+n/i);
		}
		if(m==r) sum-=r;
		//if(n==1) sum-=1;
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
