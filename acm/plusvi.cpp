//the template by dvdreddy

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  for(int i=0;i<n;i++)

#define ll long long


int main(){
  //int n;
  //cout<<"adfadf"<<endl;
  
  // return 0;
  int n;
  string a[2000];
  s(n);

  fr(i,n){
    cin>>a[i];

  }
  // cout<<n<<endl;

  long long res=0;
  f(i,1,n-1){
    f(j,1,n-1){
      if(a[i][j]=='1'){


	int v=min(n-1-j,j);
	v=min(v,i);
	v=min(v,n-1-i);

	int val_min=n;

	for(int k=1;k<=v;k++){

	  if(a[i][j-k]=='1' && a[i][j+k]=='1' && a[i+k][j]=='1' && a[i-k][j]=='1' ){
	   int  tmp=0;
	    for(int p=1;p<=v;p++){
	      if(a[i-p][j-k]=='0' && a[i+p][j-k]=='0' && a[i+p][j+k]=='0' && a[i-p][j+k]=='0' ){
		tmp++;
	      }
	      else{
		break;
	      }
	    }
	    val_min=min(val_min,tmp);




	    if(val_min>=k){res++;}
	    else{break;}

	  }
	  else{
	    break;
	  }
	}

      }
    }
  }

  printf("%lld\n",res);
  
  
}
