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
  int y;
  int cl;
};

#define ppi pair<pi,int>

int nx[]={-1,1,0,0};
int ny[]={0,0,-1,1};

char a[100][100];
bool disc[100][100][18];
char c[1000];
int res;
int n,m;
pi first,node;

void bfs(pi st){
  queue<ppi> q;
  q.push(ppi(st,0));
  while(1) {
    pi x=q.front().first;
    int dist=q.front().second;
    q.pop();
    disc[x.first][x.second]=false;    
    for(int i=0;i<4;i++){
      int x_n=x.first+nx[i];
      int y_n=x.second+ny[i];
      if(x_n<n && y_n<m && a[x_n][y_n] && disc[x_n][y_n]){
	q.push(ppi(pi(x_n,y_n),dist+1));
      }
    }
    if(q.empty()){
      node=x;res=dist;
      break;
    }
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    //cout<<"das"<<endl;
    scanf("%d",&m);
    scanf("%d",&n);
    bool fl=false;
    //  cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++){
      scanf("%s\n",c);
      for(int j=0;j<m;j++){
	disc[i][j]=true;
	if(c[j]=='#') a[i][j]=0;
	else {
	  a[i][j]=1;
	  if(!fl){
	    first=pi(i,j);
	    fl=true;
	  }
	}
      }
    }
    //  cout<<"dads \n";
    bfs(first);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	disc[i][j]=true;
      }
    }
    bfs(node);
    printf("Maximum rope length is %d.\n",res);
    
    
  }
  return 0;
}

