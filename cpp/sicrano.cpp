#include <iostream>
#include <cstdio>
using namespace std;

#define get_int(x) scanf("%d",&x)
#define sq(x) x*x

int x[50];
int y[50];


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
      get_int(x[i]);get_int(y[i]);
    }
    while(m--){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      int res=0;
      for(int i=0;i<n;i++){
	if((x[i]-a)*(d-b)== (y[i]-b)*(c-a)){
	  if((x[i]-a)*(x[i]-c)<=0 &&(y[i]-b)*(y[i]-d)<=0 )
	    res++;
	}
      }
      printf("%d\n",res);
    }


  }
  return 0;
}
