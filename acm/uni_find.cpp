#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

struct ed{
	int x;int y;int z;
};

int map[100000];
ed v[400000];
int n,m,ncount;
long long res;

bool comp(ed a,ed b){
	if(a.z<b.z) return true;
	else return false;
}

int a[100000];
int wt[100000];

int parent (int x){
  while(x!=a[x]){
    int temp=a[x];
    a[x]=a[a[x]];
    x=temp;
  }
  return x;
}

char s[100000];

int main(){
  int t;
  cin>>t;
  while(t--){
		//map.clear();v.clear();
    scanf("%d %d\n",&n,&m);char c;
    res=0;ncount=1;
    scanf("%s\n",s);
    for(int i=0;i<n;i++){
      c=s[i];
      if(c=='R'){
	map[i]=0;
      }
      else{
	map[i]=ncount;
	ncount++;
      }
    }
    int k=0;
    for(int i=0;i<m;i++){
      int x,y;int z;
      scanf("%d %d %d\n",&x,&y,&z);x--;y--;
      if(z<0) {res+=z;z=0;}
      x=map[x];y=map[y];
      if(x!=y){
	
	//cout<<x<<" "<<y<<" "<<z<<endl;
	v[k].x=x;v[k].y=y;v[k].z=z;
	k++;	
      }
    }	
    sort(v,v+k,comp);
    
    //cout<<ncount<<endl;
    for(int i=0;i<ncount;i++){
      a[i]=i;wt[i]=1;
    }
    int count=0;
    int i=0;
    //cout<<"dbg\n";
    while(count<ncount-1){
      
      int t1,t2;
      t1=parent(a[v[i].x]);
      t2=parent(a[v[i].y]);
      //cout<<i<<" "<<t1<<" "<<t2<<" "<<count<<endl;
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
	count++;
      }	
      i++;
    }	
    
    printf("%lld\n",res);	
    
  }
  
  return 0;
}

