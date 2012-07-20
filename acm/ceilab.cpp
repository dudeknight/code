#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
	int a,b;
	cin>>a>>b;

	int c=fabs(a-b);

	if(c%10!=0){
		cout<<c-1<<endl;
	}
	else{
		cout<<c+1<<endl;
	}

	return 0;
}
