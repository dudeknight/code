/*
ID: dvdeepa1
PROG: milk
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

struct fm{
	int p;
	int q;
};

bool comp(fm a,fm b){
	if(a.p<b.p)
		return true;
	else
		return false;
}

int main(){

	fstream f("milk.in",fstream::in);

	vector<fm> v;
	int m,n;f>>m>>n;
	for(int i=0;i<n;i++){
		fm farm;
		f>>farm.p>>farm.q;
		v.push_back(farm);
	}
	sort(v.begin(),v.end(),comp);

	int res=0;
	for(int i=0;i<n && m>0 ;i++){
		int vs=min(m,v[i].q);
		m-=vs;
		res+=(vs*(v[i].p));
	}

	
	f.close();
	fstream f1("milk.out",fstream::out);	
	
	f1<<res<<endl;
	f1.close();

	return 0;
}



