/*
ID: dvdeepa1
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

//#define f cin
//#define f1 cout

char c[30000];

int main(){

	//ifstream f;
	//f.open("calfflac.in");

	FILE* f;
	f=fopen("calfflac.in","r");
	char d;int k=0;
	d=fgetc(f);
	while(d!=EOF){
		c[k]=d;k++;
		d=fgetc(f);
	}
	c[k]='\0';
	fclose(f);

	string s="";
	vector<int> v;
	k=0;
	//cout<<c;
	for (int i=0;i<strlen(c);i++){
		if(c[i]<='Z' && c[i] >= 'A'){
			d=c[i]-'A'+'a';
			s+=d;k++;v.push_back(i);
		}
		else if(c[i]<='z' && c[i]>='a'){
			s+=c[i];k++;v.push_back(i);
		}
	}

	int maxi=1;int start=0,end=0;

	int n=s.size();

	for(int i=1;i<n;i++){
		int sz=1;
		k=1;
		while(k<min(i+1,n-i)){
			if(s[i-k]==s[i+k]){
				sz++;
			}
			else{
				break;
			}
			k++;
		}
		if(maxi<2*sz-1){
			start=i-k+1;
			end=i+k-1;maxi=2*sz-1;
		}
		sz=0;k=1;
		
		while(k<min(i+1,n-i+1)){
			if(s[i-k]==s[i+k-1]){
				sz++;
			}
			else{
				break;
			}
			k++;
		}
		if(maxi<2*sz){
			start=i-k+1;
			end=i+k-2;maxi=2*sz;
		}
	}



	/*
	f.close();*/
	fstream f1("calfflac.out",fstream::out);	
	
	
	f1<<maxi<<endl;
	for(int i=v[start];i<=v[end];i++){
		f1<<c[i];
	}
	f1<<endl;
	f1.close();

	return 0;
}



