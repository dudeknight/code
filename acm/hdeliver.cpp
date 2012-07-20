#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;


#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;



struct ed{
  int x;int y;
};


ed v[1003];
int n,m,ncount;


int a[1000];
int wt[100];

int parent (int x){
  while(x!=a[x]){
    int temp=a[x];
    a[x]=a[a[x]];
    x=temp;
  }
  return x;
}



int main(){
  int t,q;
  int t1,t2;
  s(t);
  while(t--){
    s(n);s(m);
    fr(i,m){
      s(v[i].x);s(v[i].y);
    }

    for(int i=0;i<n;i++){
      a[i]=i;wt[i]=1;
    }

    fr(i,m){
      t1=parent(a[v[i].x]);
      t2=parent(a[v[i].y]);
      if(t1!=t2){
	if(wt[t1]<wt[t2]){
	  a[t1]=t2;
	  wt[t2]+=wt[t1];
	}
	else{
	  a[t2]=t1;
	  wt[t1]+=wt[t2];
	}
      }	
    }

    fr(i,n)
      wt[i]=parent(a[i]);
    s(q);
    fr(i,q){
      s(t1);s(t2);
      if(wt[t1]==wt[t2])
	printf("YO\n");
      else
	printf("NO\n");
    }
		
  }

  return 0;
}

