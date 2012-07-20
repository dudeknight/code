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
int a[100][256];

bool comp(int xa,int xb,int m){
	int *a=new int [m];
	int *b=new int[m];
	for(int i=m-1;i>-1;i--){
		a[i]=xa%2;xa=xa/2;
		b[i]=xb%2;xb=xb/2;
	}
	if(a[0]==1 && (a[1]+b[0])%2!=0) return false;
	if(b[0]==1 && (a[0]+b[1])%2!=0) return false;	
	if(a[m-1]==1 && (a[m-2]+b[m-1])%2!=0) return false;
	if(b[m-1]==1 && (a[m-1]+b[m-2])%2!=0) return false;
	for(int i=1;i<m-1;i++){
		if(a[i]==1 && (a[i-1]+a[i+1]+b[i])%2!=0) return false;
		if(b[i]==1 && (b[i-1]+b[i+1]+a[i])%2!=0) return false;		
	}
	
	return true;
}

bool fa[256][256];long long mod=1000000007;
long long res[100][256];
int DengklekPaintingSquares::numSolutions(int N, int M) {
		
	int v=pow(2,M);
	
	if(M==1 || N==1) return 0;
	
	for(int i=0;i<v;i++){
		for(int j=i;j<v;j++){
			fa[i][j]=comp(i,j,M);
			fa[j][i]=fa[i][j];
		}
	}
	
	for(int i=0;i<v;i++){
		res[0][i]=1;
	}
	
	for(int i=0;i<N-1;i++){
		for(int j=0;j<v;j++){
			for(int k=0;k<v;k++){
				if(fa[j][k]) {res[i+1][k]+=a[i][j];res[i+1][k]%=mod;}
				
			}
		
		}
	}
	long long tot=0;
	
	for(int i=0;i<v;i++){
		tot+=res[N-1][i];
		tot%=mod;
	
	}
	
	return tot;
		
}


//Powered by [KawigiEdit] 2.0!