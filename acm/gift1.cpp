/*
ID: dvdeepa1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	int np;
	map<string,int> exp;
	vector<string> v;
	fstream f("gift1.in",fstream::in);
	f>>np;
	for (int i=0;i<np;i++){
		string s;
		f>>s;v.push_back(s);
		exp[s]=0;
	}
	
	for(int i=0;i<np;i++){
		string s;f>>s;
		int m,ng;
		f>>m>>ng;
		if(ng!=0){
			exp[s]+=m%ng-m;
			for(int j=0;j<ng;j++){
				f>>s;
				exp[s]+=m/ng;
			}
		}
	}
	f.close();
	fstream f1("gift1.out",fstream::out);	

	for(int i=0;i<np;i++){
		f1<<v[i]<<" "<<exp[v[i]]<<endl;
	}
	f1.close();

	return 0;
}



