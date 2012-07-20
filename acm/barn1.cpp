/*
ID: dvdeepa1
PROG: barn1
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


int main(){

	fstream f("barn1.in",fstream::in);
	int m,s,c;
	m=min(m,c);
	vector<int> v1,v2;
	f>>m>>s>>c;
	for(int i=0;i<c;i++){
		int n;f>>n;
		v1.push_back(n);
	}
	sort(v1.begin(),v1.end());
	int res=v1[0]-1+s-v1[v1.size()-1];

	for(int i=1;i<c;i++){
		int n=v1[i]-v1[i-1]-1;
		if(n==0) continue;
		v2.push_back(n);	
	}
	sort(v2.begin(),v2.end());
	int temp=v2.size();
	//cout<<temp<<endl;
	m=min(m,temp+1);
	for(int i=1;i<m;i++){
		res+=v2[v2.size()-i];
	}


	
	f.close();
	fstream f1("barn1.out",fstream::out);	
	
	f1<<s-res<<endl;

	f1.close();

	return 0;
}



