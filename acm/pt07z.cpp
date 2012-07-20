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

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

#define pi pair<int,int>
typedef long long ll;

#define size 10000
#define deg 10
#define sz(x) x.size()

bool disc[size];
vector< vector<int> > conn(10000,vector<int>(1,0));

queue<pi> q;
int n,ngh;
int node;int res;

void bfs(int st){
  while(!q.empty()) q.pop();
  q.push(pi(st,0));
  fr(i,n) 
    disc[i]=true;
  disc[st]=false;
  while(1){
    int x=q.front().first;
    int dist=q.front().second;
    q.pop();
    
    ngh=conn[x][0];
    
    f(i,1,ngh+1){
      if(disc[conn[x][i]]){
	q.push(pi(conn[x][i],dist+1));
	disc[conn[x][i]]=false;
      }
    }
    if(q.empty()){
      node=x;res=dist;
      return;
    }

  }
  return ;
}


int main(){
  s(n);
  int x,y;

  fr(i,n-1){
    s(x);s(y);x--;y--;
    conn[x].push_back(y);conn[x][0]++;
    conn[y].push_back(x);conn[y][0]++;
  }

  bfs(0);
  bfs(node);
  printf("%d",res);
  return 0;

}
