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


ed v[20003];
int n,m,ncount;


int a[10000];
int wt[10000];

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
  t=1;
  while(t--){
    s(n);s(m);
    fr(i,m){
      s(v[i].x);s(v[i].y);
      v[i].x--;v[i].y--;
    }

    if(m!=n-1){
      printf("NO\n");
      continue;
    }
      

    for(int i=0;i<n;i++){
      a[i]=i;wt[i]=1;
    }

    int res=n;
    fr(i,m){
      t1=parent(a[v[i].x]);
      t2=parent(a[v[i].y]);
      if(t1!=t2){
	res--;
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

    if(res==1){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }



		
  }

  return 0;
}

