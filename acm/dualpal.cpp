/*
ID: dvdeepa1
PROG: dualpal
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

int n,st;
char num[10000];
int len;
string s;

void conv(int n,int b){
	len=0;
	while(n!=0){
		num[len]=s[n%b];
		n/=b;
		len++;
	}
	for(int i=0;i<len/2;i++){
		swap(num[i],num[len-1-i]);	
	}
	num[len]='\0';

}

bool check(){
	for(int i=0;i<len/2;i++){
		if(num[i]!=num[len-1-i])
			return false;
	}
	return true;
}

int main(){

	fstream f("dualpal.in",fstream::in);

	f>>n>>st;	

	s="0123456789ABCDEFGHIJ";
	
	f.close();
	fstream f1("dualpal.out",fstream::out);	
	
	for(int i=st+1;n!=0;i++){
		int scr=2;
		for(int b=2;b<=10 && scr!=0;b++){
			conv(i,b);
			if(check()) scr--;
		}
		if(scr==0) {
			n--;
			f1<<i<<endl;
		}
	}

	f1.close();

	return 0;
}



