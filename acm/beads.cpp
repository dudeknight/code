/*
ID: dvdeepa1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#define f cin
//#define f1 cout

int dps[1000];
int dpr[1000];
int sdp[1000];
int rdp[1000];
int main(){
	string s;
	fstream f("beads.in",fstream::in);
	f>>s;
	f>>s;
	s+=s;int n=s.size();
	//cout<<n<<" "<<s<<endl;
	
	sdp[0]=1;
	char c=s[0];int count=1;
	for(int i=1;i<n;i++){
		if(s[i]==c){
			count++;
		}
		else{
			count=1;c=s[i];
		}
		sdp[i]=count;
	}
	rdp[n-1]=1;
	c=s[n-1];count=1;
	for(int i=n-2;i>=0;i--){
		if(s[i]==c){
			count++;
		}
		else{
			count=1;c=s[i];
		}
		rdp[i]=count;
	}

	dps[0]=1;
	c=s[0];count=1;
	for(int i=1;i<n;i++){
		if(s[i]=='w' || s[i]==c||c=='w'){
			if(c=='w' && s[i]!='w')
				c=s[i];
			count++;
		}
		else{
			if(s[i-1]=='w'){
				count=1+sdp[i-1];
			}
			else
				count=1;
			c=s[i];
		}
		dps[i]=count;
	}
	dpr[n-1]=1;
	c=s[n-1];count=1;
	for(int i=n-2;i>=0;i--){
		if(s[i]=='w' || s[i]==c || c=='w'){
			if(c=='w' && s[i]!='w')
				c=s[i];
			count++;
		}
		else{
			if(s[i+1]=='w'){
				count=1+rdp[i+1];
			}
			else
				count=1;
			c=s[i];
		}
		dpr[i]=count;
	}
	int maxx=0;
	for(int i=1;i<n;i++){
		maxx=max(maxx,dps[i-1]+dpr[i]);
	}
	
	for(int i=0;i<n;i++){
	//	cout<<s[i]<<' '<<dps[i]<<" "<<dpr[i]<<endl;
	}

	f.close();
	fstream f1("beads.out",fstream::out);	

	if(maxx>n/2) maxx=n/2;
	f1<<maxx<<endl;
	f1.close();

	return 0;
}



