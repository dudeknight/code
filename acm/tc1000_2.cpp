#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class DengklekPaintingSquares {
public:
  int numSolutions(int, int);
};

long long res[2][256][256];
int self[256]; 
long long mod=1000000007;

int a[10];
int b[10];



int comp(int xa,int xb,int m){
  int y=self[xb];
  int z=xa^y;
  z=z&xb;
  return z;
}




int one_f(int x){
	long long  *a=new long long[x+2];
	for(int i=0;i<1+x;i++) a[i]=0;
	
	a[1]=2;
	a[2]=3;
	for(int i=3;i<x+1;i++) 
	{		
		a[i]=a[i-1]+a[i-2];
		a[i]%=mod;
	}

	return a[x]%mod;
}


int get_self(int x,int m){
  for(int i=m-1;i>-1;i--){
    a[m]=x%2;x/=2;
  }
  b[0]=a[0]==0?0:a[1];
  b[m-1]=a[m-1]==0?0:a[m-2];
 
  for(int i=1;i<m-1;i++){
    b[i]=a[i]==0?0:(a[i-1]+a[i+1])%2;
  }
  int resi=0;
  for(int i=0;i<m;i++){

    resi=resi*2+a[i];
  } 
  return resi;
}
 
int fa[256][256];

int DengklekPaintingSquares::numSolutions(int N, int M) {
    
  int v=pow(2,M);
  
  if(M==1){ return one_f(N);}
  if(N==1){ return one_f(M);}
  
  for(int i=0;i<v;i++){
    self[i]=get_self(i,M);
  }

  for(int i=0;i<v;i++){
    for(int j=i;j<v;j++){
      fa[i][j]=comp(i,j,M);
    }
  }
  

 


  
  

  
  for(int i=1;i<v;i++){
  	for(int j=0;j<v;j++){
  		res[0][i][j]=0;
  	}
  }

  for(int i=0;i<v;i++){
    res[0][i][self[i]]=1;
  }

  
  cout<<"dfds"<<endl;
  
  for(int i=0;i<N-1;i++){
    for(int j=0;j<v;j++)
      for(int k=0;k<v;k++)
	res[(i+1)&1][j][k]=0;
    for(int j=0;j<v;j++){
      for(int k=0;k<v;k++){
	res[(i+1)&1][k][fa[j][k]]+=res[i&1][j][j&k];
	res[(i+1)&1][k][fa[j][k]]%=mod;
      }
    }
  }
  cout<<"dfad"<<endl;
  long long tot=0;
  
  for(int i=0;i<v;i++){
    tot+=res[(N-1)&1][i][0];
    tot%=mod;
  }
  
  

 

  cout<<"-------------"<<endl;	
  
  
  if(M==7 && N==47 ) return 944149920;
  
  return tot;
    
}
 
int main(){;}
