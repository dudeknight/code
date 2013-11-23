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
  int x;int y;ll z;
};

int map[100000];
ed v[2000000];
int n, m, k;
ll res;

bool comp(ed a,ed b){
  if(a.z < b.z) return true;
  else return false;
}

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
  int t;
  s(t);
  while(t--){

    s(n); s(m); s(k);
    res = 0;
    fr (i, m){
      int x, y; ll z;
      s(x); s(y); sll(z);
      v[i].x = x - 1;
      v[i].y = y - 1;
      v[i].z = z;
    }
    sort(v, v + m, comp);
    
    for(int i=0;i<n;i++){
      a[i]=i;wt[i]=1;
    }
    int count = n;
    int i=0;

    while(count > k  && i < m){
      int t1,t2;
      t1=parent(a[v[i].x]);
      t2=parent(a[v[i].y]);
 
      if(t1!=t2){
	res+=v[i].z;
	if(wt[t1]<wt[t2]){
	  a[t1]=t2;
	  wt[t2]+=wt[t1];
	}
	else{
	  a[t2]=t1;
	  wt[t1]+=wt[t2];
	}
	count--;
      }	
      i++;
    }	
    
    if (count > k){
      printf("Impossible!\n");
    } else {
      printf("%lld\n",res);	
    }
    
  }
  
  return 0;
}

