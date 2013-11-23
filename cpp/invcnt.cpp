#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;i++)

long long a[200000];
long long b[200000];
int n;


void mymerge(int i,int j,int k){
	int x=i;
	int y=j;
	int c=i;	
	while(x<j and y<k){
		if(a[x]<=a[y]){
			b[c]=a[x];x++;
		}
		else{
			b[c]=a[y];y++;
		}
		c++;
	}
	while(x<j){
		b[c]=a[x];x++;c++;
	}
	while(y<k){
		b[c]=a[y];y++;c++;
	}
	f(p,i,k){
		a[p]=b[p];
	}
}



long long mycount(int i,int j,int k){
	long long res=0;
	int x=i;
	int y=j;
	while(x<j && y<k){
		if(a[x]<=a[y]){
			res+=(y-j);
			x++;
		}
		else
			y++;
	}
	while(x<j){
		res+=(k-j);
		x++;
	}

	return res;
}



long long func(){
        long long res=0;
	int m=1;
	while(m<n){
		int i=0;
		while(i<n-m){
			res+=mycount(i,i+m,min(i+2*m,n));
			mymerge(i,i+m,min(i+2*m,n));
			i+=2*m;
		}
		m*=2;
	}

	return res;
}

		


int main(){
	int t;string s;
	cin>>t;//cin>>s;
	while(t--){
		cin>>n;
		f(i,0,n)
			cin>>a[i];	
		cout<<func()<<endl;
		//cin>>s;
	}
	return 0;
}
