#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

#define maxx 9223372036854775800

long long val[50];
char op[50];
int n;



long long dpmax[100][100];
long long dpmin[100][100];

long long ev(long long x,long long y,char c){
	if(c=='*'){
		return x*y;
	}
	else{
		return x+y;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;	
		cin>>s;
		int c=0;n=0;
		for(int i=0;i<s.size();i++){
			if(s[i]>='0' && s[i]<='9'){
				continue;					
			}
			else{
				string temp=s.substr(c,i-c);
				val[n]=atoi(temp.c_str());
				op[n]=s[i];
				n++;
				c=i+1;
			}
		}
		string temp=s.substr(c);
		val[n]=atoi(temp.c_str());
		n++;
		//cout<<n<<endl;
		
		for(int i=0;i<n;i++){
			dpmax[i][i]=val[i];
			dpmin[i][i]=val[i];
		}

		for(int i=1;i<n;i++){
			for(int j=0;j<n-i;j++){
				long long rmin=maxx;
				long long rmax=0;
				for(int k=j;k<j+i;k++){
					long long intrm1=ev(dpmax[j][k],dpmax[k+1][j+i],op[k]);
					long long intrm2=ev(dpmin[j][k],dpmin[k+1][j+i],op[k]);
					rmax=max(rmax,intrm1);
                			rmin=min(rmin,intrm2);
				}
			        dpmax[j][j+i]=rmax;
        			dpmin[j][j+i]=rmin;
			}
		}

		cout<<dpmax[0][n-1]<<" "<<dpmin[0][n-1]<<endl;
	}
	return 0;

}
