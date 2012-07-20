/*
ID: dvdeepa1
PROG: transform
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

vector<string> target;
int n;

bool comp(vector<string> a){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=target[i][j]){
				return false;
			}
		}
	}
	return true;
}

vector<string> rot(vector<string> a){
	vector<string> nv(a);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			nv[j][n-1-i]=a[i][j];	
		}
	}
	return nv;
}
bool deg90(vector<string> a){
	return comp(rot(a));
}

bool deg180(vector<string> a){
	return comp(rot(rot(a)));
}

bool deg270(vector<string> a){
	return comp(rot(rot(rot(a))));
}

vector<string> mirr(vector<string> a){
	vector<string> nv(a);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			nv[i][n-1-j]=a[i][j];	
		}
	}
	return nv;	
}

bool ref(vector<string> a){
	return comp(mirr(a));
}


bool comb(vector<string> a){
	return (comp(rot(mirr(a))) ||  comp(rot(rot(mirr(a)))) || comp(rot(rot(rot(mirr(a))))));
}

typedef bool (*func) (vector<string> a);



int main(){
	
	vector<string> source;
	fstream f("transform.in",fstream::in);
	f>>n;
	for(int i=0;i<n;i++){
		string s;f>>s;
		source.push_back(s);
	}
	for(int i=0;i<n;i++){
		string s;f>>s;
		target.push_back(s);
	}
		
	
	func functions[]={deg90,deg180,deg270,ref,comb,comp};
	int mapper[]={1,2,3,4,5,6,7};
	int i;
	for(i=0;i<6;i++){
		if(functions[i](source)) break;
	}
	
	f.close();
	fstream f1("transform.out",fstream::out);	
	
	f1<<mapper[i]<<endl;
	f1.close();

	return 0;
}



