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
#define fr(i,n)  f(i,0,n)

typedef long long ll;

//#define pi pair<int,int>


struct pi{
  int x;
  ll y;
  int cl;
};

#define ppi pair<pi,int>

#define lim 20001


int a[20001];
bool *b;
bool *bt,*temp;
int res,node;
int m,len,tmp;



int main(){
  b=new bool[20001];
  bt=new bool[20001];

  int t;
  s(t);
  //  cout<<t<<endl;
  while(t--){
    s(m);
    //    cout<<m<<endl;
    if(m==1){
      printf("1\n");
      continue;
    }
    fr(i,m){
      fr(j,2)
	b[i]=false;
    }
    a[0]=0;a[1]=1;
    b[1]=true;b[0]=true;
    res=10%m;len=1;int itr=1,pritr=0;
    while(1){
      itr=len&1;
      fr(i,m)
	bt[i]=b[i];
      fr(i,m){
	tmp=(i+res)%m;
	//cout<<i<<" "<<res<<" "<<tmp<<" "<<b[i]<<endl;
	if(tmp==0 && b[i]){
	  a[0]=a[i]|(1<<len);
	  break;
	}
	if(b[i] && !b[tmp]){
	  bt[tmp]=true;
	  a[tmp]=a[i]|(1<<len);
	}
      }
      if(b[0] && a[0]){
	node=a[0];	
	break;
      }
      swap(b,bt);
      res*=10;res%=m;
      len++;
    }
    res=0;
    for(int i=0;i<=len;i++){
      res=res*2+node%2;
      node/=2;
    }

    for(int i=0;i<=len;i++){
      printf("%d",res%2);
      res/=2;
    }
    printf("\n");  
    
 
  }
  return 0;
}

