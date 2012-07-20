


#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;i++)

long long a[200000];
long long b[200000];
int n;


void mymerge(int i,int j,int k){
  int x=i;
  int y=j;
  int c=i;
  while(x<j and y<k){
    if(a[x]<=a[y]){
      b[c]=a[x];x++;
    }
    else{
      b[c]=a[y];y++;
    }
    c++;
  }
  while(x<j){
    b[c]=a[x];x++;c++;
  }
  while(y<k){
    b[c]=a[y];y++;c++;
  }
  f(p,i,k){
    a[p]=b[p];
  }
}



long long mycount(int i,int j,int k){
  long long res=0;
  int x=i;
  int y=j;
  while(x<j && y<k){
    if(a[x]<=a[y]){
      res+=(y-j);
      x++;
    }
    else
      y++;
  }
  while(x<j){
    res+=(k-j);
    x++;
  }

  return res;
}



long long func(){
  long long res=0;
  int m=1;
  while(m<n){
    int i=0;
    while(i<n-m){
      res+=mycount(i,i+m,min(i+2*m,n));
      mymerge(i,i+m,min(i+2*m,n));
      i+=2*m;
    }
    m*=2;
  }

  return res;
}






int main(){
  int t,tempn;string s;
	cin>>t;//cin>>s;
	int layer_posz;
	int layer_posxy;
	while(t--){
		cin>>tempn;
		n=0;
		for(int i=0;i<tempn;i++){
		  for(int j=0;j<(tempn*tempn);j++){
		    int c;cin>>c;
		    if(c==0){
		      layer_posz=i;
		      layer_posxy=j;
		    }
		    else{
		      a[n]=c;n++;
		      //cout<<c<<" ";
		    }
		  }
		}
		//		for(int i=0;i<n;i++){
		//cout<<a[i]<<" ";
		//}
		//	cout<<endl;
		//cout<<tempn<<" "<<n<<endl;
		int res=func();
		//cout<<res<<endl;
		
		bool b=(tempn%2==1 && res%2==0);
		b=b || (tempn%2==0 && ((tempn-1-layer_posz+(tempn-1-(layer_posxy/tempn)))%2==res%2));
		if(b)
		  cout<<"Puzzle is solvable.\n";
		else
		  cout<<"Puzzle is unsolvable.\n";
		
		//cin>>s;
	}
	return 0;
}
