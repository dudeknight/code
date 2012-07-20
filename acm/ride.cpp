/*
ID: dvdeepa1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

	string a,b;
	fstream f("ride.in",fstream::in);
	f>>a>>b;
	f.close();

	int ra=1,rb=1;
	for(int i=0;i<a.size();i++){
		ra*=(a[i]-'A'+1);
		ra%=47;
	}
	for(int i=0;i<b.size();i++){
		rb*=(b[i]-'A'+1);
		rb%=47;
	}

	fstream g("ride.out",fstream::out);

	if(rb%47==ra%47)
		g<<"GO\n";
	else
		g<<"STAY\n";

	g.close();

	return 0;

}
