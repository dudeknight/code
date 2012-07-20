/*
ID: dvdeepa1
PROG: namenum
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

long long n;
vector<string> res;

long long mapp(string s){
	long long res=0;
	for(int i=0;i<s.size();i++){
		int let=s[i]-'A';
		if(let>='R'-'A') let--;
		let/=3;
		res*=10;
		res+=(let+2);
	}
	//cout<<res<<endl;
	return res;
}
int main(){

	fstream f("namenum.in",fstream::in);
	
	f>>n;

	
	f.close();
	fstream f1("namenum.out",fstream::out);	
	

	fstream dic("dict.txt",fstream::in);
	string s="KRISTOPHER";
	while(dic>>s){
		//cout<<mapp(s)<<endl;
		//cout<<n<<endl;
		if(mapp(s)==n){
			//cout<<"in the loop \n";
			res.push_back(s);	
		}	
		//break;
	}
	dic.close();
	for(int i=0;i<res.size();i++)
		f1<<res[i]<<endl;
	if(res.size()==0)
		f1<<"NONE"<<endl;
	f1.close();

	return 0;
}



