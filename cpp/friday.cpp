/*
ID: dvdeepa1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//#define f cin
//#define f1 cout

int main(){
	int n;
	fstream f("friday.in",fstream::in);
	vector<int> res(7,0);
	f>>n;
	int total=0;
	int feb,y;
	int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i=1900;i<1900+n;i++){
		if(i%100!=0 &&i%4==0){
			feb=29;y=366;
		}
		else if(i%100==0 && i%400==0){
			feb=29;y=366;
		}
		else{
			feb=28;y=365;
		}
		m[1]=feb;
		for(int j=0;j<12;j++){
			res[(total+13)%7]+=1;
			total+=m[j];
		}
	}
	
	f.close();
	fstream f1("friday.out",fstream::out);	

	for(int i=0;i<6;i++){
		f1<<res[(i+6)%7]<<" ";
	}
	f1<<res[5]<<endl;
	f1.close();

	return 0;
}



