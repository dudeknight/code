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

map<char,int> mp;

char a[100][100];
int disc[100][100][18];
char c[100][100];
int res;
int n,m;
bool sol;

void bfs(pi st){
  queue<ppi> q;
  q.push(ppi(st,0));
  while(1) {
    pi x=q.front().first;
    int dist=q.front().second;
    dist++;
    q.pop();
    disc[x.x][x.y][x.cl]=false;    

    for(int i=0;i<4;i++){
      int x_n=x.x+nx[i];
      int y_n=x.y+ny[i];
      int cl=x.cl;


      if(x_n<=n-1 && x_n>=0 && y_n<=m-1 && y_n>=0 && disc[x_n][y_n][cl]){
	  char c_n=c[x_n][y_n];
	  if(c_n=='X'){
	    sol=true;res=dist;
	    break;
	  }
	  else if(c_n=='#'){
	    continue;
	  }
	  else if(c_n>='A' && c_n<='Z'){
	    if(!(cl&mp[c_n])){
	      //cout<<x_n<<" "<<y_n<<endl;
	      continue;
	    }
	  }
	  else if(c_n>='a' && c_n<='z'){
	    cl=cl|mp[c_n];
	  }
	  
	  pi tmp;
	  
	  tmp.x=x_n;
	  tmp.y=y_n;
	  tmp.cl=cl;
	  //printf("%d %d %d %d\n",x_n,y_n,cl,dist);
	  disc[x_n][y_n][cl]=false;
	  q.push(ppi(tmp,dist));
	    
      }

    }
    //printf("-------------------------\n");
    if(sol)
      break;

    if(q.empty()){
      sol=false;
      break;
    }
  }
}

int main(){
 
  mp['B']=1;mp['b']=1;
  mp['Y']=2;mp['y']=2;
  mp['G']=4;mp['g']=4;
  mp['R']=8;mp['r']=8;
  s(n);s(m);
  while(n!=0){
   
     
    pi st;
    
    for(int i=0;i<n;i++){
      scanf("%s",c[i]);
      //printf("%s\n",c[i]);
      for(int j=0;j<m;j++){
	fr(k,16)
	  disc[i][j][k]=true;
        if(c[i][j]=='*'){
	  st.x=i;st.y=j;
	  st.cl=0;
	}
      }
    }
    
    bfs(st);
      
    if(sol)
      printf("Escape possible in %d steps.\n",res);
    else
      printf("The poor student is trapped!\n");
    s(n);s(m);
    sol=false; 
  }
  return 0;
}
