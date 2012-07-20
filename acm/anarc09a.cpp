#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string s;
	cin>>s;
	int c=1;
	while(s[0]!='-'){
		int n=s.size();
		int count=0;
		int res=0;
		for(int i=0;i<n;i++){
			if(s[i]=='{')
				count++;
			else{
				if(count==0){
					count++;
					res++;
				}
				else
					count--;
			}
		}
		res+=(count/2);
		printf("%d. %d\n",c++,res);
		cin>>s;
	}

	return 0;
}

