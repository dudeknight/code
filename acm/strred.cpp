#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int a[100][100][3];

void cal(int x,int y){
	bool flag=false;
	if(a[x][y][0]==200 && a[x][y][1]==200 &&a[x][y][2]==200) flag=true;

	if(flag){
		for(int i=x;i<y;i++){	
			cal(x,i);	
			cal(i+1,y);
			int m=a[x][i][0];
			if(m<=100){
				int k=a[i+1][y][0];
				if(k<=100){	
					int tot=m+k;
					a[x][y][0]=min(a[x][y][0],tot);
				}
				k=a[i+1][y][1];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][0]=min(a[x][y][0],2);
							a[x][y][1]=min(a[x][y][1],2);
						}
						else{
							a[x][y][2]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][0]=1;
						}
						else{
							a[x][y][1]=1;
						}
						
					}
				}
				k=a[i+1][y][2];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][0]=min(a[x][y][0],2);
							a[x][y][2]=min(a[x][y][1],2);
						}
						else{
							a[x][y][1]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][0]=1;
						}
						else{
							a[x][y][2]=1;
						}
						
					}
				}
			}

			m=a[x][i][2];
			if(m<=100){
				int k=a[i+1][y][2];
				if(k<=100){	
					int tot=m+k;
					a[x][y][2]=min(a[x][y][2],tot);
				}
				k=a[i+1][y][1];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][2]=min(a[x][y][2],2);
							a[x][y][1]=min(a[x][y][1],2);
						}
						else{
							a[x][y][0]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][2]=1;
						}
						else{
							a[x][y][1]=1;
						}
						
					}
				}
				k=a[i+1][y][0];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][0]=min(a[x][y][0],2);
							a[x][y][2]=min(a[x][y][1],2);
						}
						else{
							a[x][y][1]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][2]=1;
						}
						else{
							a[x][y][0]=1;
						}
						
					}
				}


			}

			m=a[x][i][1];
			if(m<=100){
				int k=a[i+1][y][1];
				if(k<=100){	
					int tot=m+k;
					a[x][y][1]=min(a[x][y][1],tot);
				}
				k=a[i+1][y][0];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][0]=min(a[x][y][0],2);
							a[x][y][1]=min(a[x][y][1],2);
						}
						else{
							a[x][y][2]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][1]=1;
						}
						else{
							a[x][y][0]=1;
						}
						
					}
				}
				k=a[i+1][y][2];
				if(k<=100){
					if(abs(m-k)%2==0){
						if(m%2==0){
							a[x][y][1]=min(a[x][y][1],2);
							a[x][y][2]=min(a[x][y][1],2);
						}
						else{
							a[x][y][0]=1;
						}
					}
					else{
						if(m>k){
							a[x][y][1]=1;
						}
						else{
							a[x][y][2]=1;
						}
						
					}
				}
			}
		}

	}

	return ;
}




int main(){
	int test;cin>>test;

	while(test>0){
		cin>>s;
		for(int i=0;i<s.size();i++){
			for(int j=0;j<s.size();j++){
				for(int k=0;k<3;k++)
					a[i][j][k]=200;
			}
		}
		
		for(int i=0;i<s.size();i++){
			a[i][i][s[i]-'a']=1;
		}
		int mini=200;
		cal(0,s.size()-1);
		mini=min(mini,a[0][s.size()-1][0]);
		mini=min(mini,a[0][s.size()-1][1]);
		mini=min(mini,a[0][s.size()-1][2]);
		cout<<mini<<endl;
		test--;

	}

	return 0;

}
