/*
ID: dvdeepa1
PROG: milk2
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

struct p{
	int st;
	int end;
};

bool func(p a,p b){
	if(a.st<b.st){
		return true;
	}
	else if(a.st==b.st){
		if(a.end<b.end){
			return true;
		}
		else {
			return false;
		}
	}
	else{
		return false;
	}
}

p a[5000];
int st[5000];
int end[5000];

int main(){
	int n;
	
	fstream f("milk2.in",fstream::in);
	f>>n;

	for(int i=0;i<n;i++){
		f>>a[i].st>>a[i].end;
	}
	
	sort(a,a+n,func);
	
	int cur=0;

	st[0]=a[0].st;
	end[0]=a[0].end;

	for(int i=1;i<n;i++){
		if(a[i].st<=a[cur].end){
			if(a[i].end>a[cur].end){
				a[cur].end=a[i].end;
			}	
		}
		else{
			cur++;
			a[cur].st=a[i].st;
			a[cur].end=a[i].end;
		}
	}

	int ans1=0;
	int ans2=0;	
	
	for(int i=0;i<=cur;i++){
		if(i){
			ans1=max(ans1,a[i].end-a[i].st);
			ans2=max(ans2,a[i].st-a[i-1].end);			
		}
		else{
			ans1=max(ans1,a[i].end-a[i].st);
		}
	}
	
	f.close();
	fstream f1("milk2.out",fstream::out);	
	

	f1<<ans1<<" "<<ans2<<endl;	

	f1.close();

	return 0;
}



