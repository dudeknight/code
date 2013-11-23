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
#define sc(x) scanf("%c",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

#define pi pair<int,int>

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};


int a[200][200];
bool tst[200][200];
queue<pi> q;
char c[200];
int temp,xx,yy,xxi,yyi;
int n,m;
int main(){
  int t;s(t);
  while(t--){

    s(n);s(m);

    fr(i,n){
      ss(c);
      fr(j,m){
	temp=c[j]-'0';
	if(temp){
	  a[i][j]=0;
	  q.push(pi(i,j));
	  tst[i][j]=0;
	}
	else{
	  a[i][j]=n+m;
	  tst[i][j]=1;
	}
      }
    }
    
    while(!q.empty()){
      xx=q.front().first;
      yy=q.front().second;
      q.pop();
      fr(i,4){
	xxi=xx+x[i];
	yyi=yy+y[i];
	if(xxi>=0 &&yyi>=0 && xxi<n &&yyi<m){
	  if(a[xxi][yyi]>a[xx][yy]+1){
	    a[xxi][yyi]=a[xx][yy]+1;
	    if(tst[xxi][yyi]){
	      q.push(pi(xxi,yyi));
	      tst[xxi][yyi]=0;
	    }
	  }
	}
      }
    }


 
    fr(i,n){
      fr(j,m){
	if(j) printf(" ");
	printf("%d",a[i][j]);
      }
      printf("\n");
    }
    
 

  }



}
