#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct brick{
	int x;
	int y;
	int z;
};

bool comp(brick a,brick b){
	if(a.x<b.x) {
		return true;
	}
	else if(a.x==b.x){
		if(a.y>b.y){
			return true;
		}
		else if(a.y==b.y){
			if(a.z>b.z){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

	


brick a[200];
long long dp[200];
int main(){
	int n,x,y,z;
	cin>>n;
	while(n){
		n*=6;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			a[i].x=x;a[i].y=y;a[i].z=z;i++;
			a[i].x=x;a[i].y=z;a[i].z=y;i++;	
			a[i].x=y;a[i].y=x;a[i].z=z;i++;
			a[i].x=y;a[i].y=z;a[i].z=x;i++;
			a[i].x=z;a[i].y=x;a[i].z=y;i++;
			a[i].x=z;a[i].y=y;a[i].z=x;		
		}

		sort(a,a+n,comp);


	
		dp[0]=a[0].z;
		for(int i=1;i<n;i++){
			int j;long long maxx=0;
			for(j=i-1;j>=0;j--){
				if(a[i].y>a[j].y){
					maxx=max(maxx,dp[j]);
				}
			}
			dp[i]=maxx+a[i].z;
		}
		
		long long maxx=dp[0];
		for(int i=1;i<n;i++){
			maxx=max(maxx,dp[i]);
		}
		/*
		for(int i=0;i<n;i++){
			cout<<i<<". "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<dp[i]<<endl;
		}		
		*/
		cout<<maxx<<endl;
		cin>>n;
	}


	return 0;
}
