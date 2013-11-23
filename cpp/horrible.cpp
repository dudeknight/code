#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


int a[100000][3];
int n;

int intr(int p,int q,int x,int y){
	int dif1=abs(p-q);
	int dif2=abs(x-y);
	int dif3=abs(p-x);
	int dif4=abs(y-q);

	if(q>n) q=n;
	if(y>n) y=n;


	if(y<p || x>q) return 0;
	if(p<=x && y<=q)
		return dif2+1;
	if(p<=x && y>q)
		return dif1+1-dif3;
	if(p>x && y<=q)
		return dif1+1-dif4;
	else
		return dif1+1;
}

int main(){

	int t;cin>>t;
	while(t>0){
		int c;
		cin>>n>>c;
		int b,p,q,v;
		int cur=0;
		for(int i;i<c;i++){
			cin>>b;
			if(b==0){
				cin>>a[cur][0]>>a[cur][1]>>a[cur][2];
				cur++;
			}
			else{
				cin>>p>>q;
				long sum=0;
				for(int i=0;i<cur;i++){
					sum+=(intr(a[i][0],a[i][1],p,q))*a[i][2];
				}
				cout<<sum<<endl;
			}
		}
		t--;
	}
	return 0;
}
