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

#define nsize 100000
#define msize 200000

typedef long long ll;
typedef pair<int,int> pi;

ll mod = 1000000000;
ll disc[nsize];
pi edges[msize];
int edges_start[nsize];
int edges_end[nsize];

int par[nsize];
int dp[nsize][2];
bool proc[nsize];
int m, n;


bool comp(pi x, pi y){
  if (x.first < y.first){
    return true;
  } else if (x.first > y.first){
    return false;
  }else {
    if (x.second < y.second){
      return true;
    } else {
      return false;
    }
  }
}

int vertex_cover(){
  queue<int> q;
  queue<int> btup;
  q.push(0);
  par[0] = -1; //does not exist
  int child_count;
  fr (i, n){
    proc[i] = false;
  }

  while (!q.empty()){
    int cur = q.front();
    q.pop();
    child_count = 0;
    f (i, edges_start[cur], edges_end[cur]){
      if (edges[i].second != par[cur]){
	q.push(edges[i].second);
	par[edges[i].second] = cur;
	child_count++;
      }
    }
    if (child_count == 0){
      btup.push(cur);
      dp[cur][0] = 0; dp[cur][1] = 1;
      proc[cur] = true;
    }
  }

  while (true){
    int cur = btup.front();
    btup.pop();
    int cur_parent = par[cur];
    if (cur_parent == -1){
      break;
    }
    
    if (proc[cur_parent]){
      continue;
    }
    dp[cur_parent][0] = 0; dp[cur_parent][1] = 1;
    bool suc = true;
    f (i, edges_start[cur_parent], edges_end[cur_parent]){
      int child = edges[i].second;
      if (par[cur_parent] != child){
	if (proc[child]){
	  dp[cur_parent][0] += dp[child][1];
	  dp[cur_parent][1] += dp[child][0];
	} else{
	  suc = false;
	  break;
	}
      }
    }
    if (suc){
      dp[cur_parent][0] = min(dp[cur_parent][1], dp[cur_parent][0]);
      proc[cur_parent] = true;
      btup.push(cur_parent);
    }
  }
  return dp[0][0];
}

int main(){
  s(n); m =  2 * (n - 1);
  fr (i, n - 1){
    s(edges[2 * i].first); edges[2 * i].first--;
    s(edges[2 * i].second); edges[2 * i].second--;
    edges[2 * i + 1].first = edges[2 * i].second;
    edges[2 * i + 1].second = edges[2 * i].first;
  }
  
  sort(edges, edges + m, comp);
  edges_start[0] = 0;
  int cur = 0;
  fr (i, m){
    while (cur != edges[i].first){
      edges_end[cur] = i;
      cur++;
      edges_start[cur] = i;
    }
  }
  edges_end[cur] = m;
  f (i, cur + 1, n){
    edges_start[i] = m;
    edges_end[i] = m;
  }
  cout << vertex_cover() << endl;
  return 0;
}

