#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
int t;
cin>>t;
int i,j,k,l,m,n,ans;
int a,b[100000];
for(i=0;i<t;i++){
scanf("%d",&b[i]);
//cout<<i<<endl;
}
//cout<<"wew\n";
for(i=0;i<t;i++){

a=b[i];
float sum=0.0;
for(j=1;j<1000000000;j++){	
	//cout<<j<<endl;
sum+=log((j+0.0)/a);
if(sum>=0){ ans=j;break;}
}
printf("%d\n",ans);
}
return 0;
}



