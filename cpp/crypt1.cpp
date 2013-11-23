/*
ID: dvdeepa1
PROG: crypt1
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


int main(){

	fstream f("crypt1.in",fstream::in);
	bool chk[11];
	for(int i=0;i<=10;i++){
		chk[i]=false;
	}
	int a[10];
	int n;f>>n;
	for(int i=0;i<n;i++){

		f>>a[i];chk[a[i]]=true;
	}
	int count=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				for(int l=0;l<n;l++)
					for(int m=0;m<n;m++){
						int c=a[i]*100+a[j]*10+a[k];
						int top=c*a[l];
						int bot=c*a[m];
						int res=bot*10+top;
						//cout<<c<<" "<<top<<" "<<bot<<endl;
						if(top>=1000 || bot>=1000||res>=10000)
							continue;
						bool flag=true;
						while(top!=0){
							if(!chk[top%10])
								flag=false;
							top/=10;
						}
						top=bot;
						while(top!=0){
							if(!chk[top%10])
								flag=false;
							top/=10;
						}
						top=res;
						while(top!=0){
							if(!chk[top%10])
								flag=false;
							top/=10;
						}
						//cout<<c<<" "<<top<<" "<<bot<<endl;

						if(flag){
							cout<<c<<" "<<a[l]<<" "<<a[m]<<endl;
						       	count++;
						}
					}
	
	f.close();
	fstream f1("crypt1.out",fstream::out);	
	
	
	f1<<count<<endl;
	//f1.close();

	return 0;
}



