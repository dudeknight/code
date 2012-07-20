/*
ID: dvdeepa1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
using namespace std;

//#define f cin
//#define f1 cout

int n;
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

	fstream f("palsquare.in",fstream::in);
	

	s="0123456789ABCDEFGHIJ";

	f>>n;
	//conv(500,n);
	//cout<<num<<endl;

	
	f.close();
	fstream f1("palsquare.out",fstream::out);	
	
	for(int i=1;i<301;i++){
		int sqr=i*i;
		conv(sqr,n);
		if(check()){
			conv(i,n);
			f1<<num<<" ";
			conv(sqr,n);
			f1<<num<<endl;
		}
	}
	f1.close();

	return 0;
}



