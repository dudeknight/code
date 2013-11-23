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

bool disc[size];
int res[size];
vector<vector<int> > conn;
queue<pi> q;
int n;
int node;int res;

void bfs(int st){
  while(!q.empty()) q.pop();
  q.push(pi(st,0));
  fr(i,n) 
    disc[i]=true;

  while(1){
    int x=q.front().first;
    int dist=q.front().second;
    q.pop();
    disc[x]=false;
    fr(int i=0;i<conn[x].size;i++){
      if(disc[conn[x][i]]){
	q.push(pi(conn[x][i],dist+1));
      }
    }
    if(q.empty()){
      node=x;res=dist;
      return;
    }

  }
}

