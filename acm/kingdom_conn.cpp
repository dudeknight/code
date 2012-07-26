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

#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

#define nsize 10000
#define msize 100000

typedef long long ll;
typedef pair<int,int> pi;

ll mod = 1000000000;
pi edges[msize];
int edges_start[nsize];
int edges_end[nsize];
pi redges[msize];
int redges_start[nsize];
int redges_end[nsize];
int m, n;

// strutures required for bfs
queue<int> q;
bool disc[nsize];
ll dp[nsize];
int in_deg[nsize];
bool tagged[nsize];

bool comp(pi x, pi y){
  if (x.first < y.first){
    return true;
  } else if (x.first == y.first){
    if (x.second < y.second){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void bfs_pre(int start){
  q.push(start);
  fr (i, n){
    disc[i] =false;
    in_deg[i] = 0;
  }
  disc[start] = true;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    f (i, edges_start[cur], edges_end[cur]){
      in_deg[edges[i].second]++;
      if (!disc[edges[i].second]){
	disc[edges[i].second] = true;
	q.push(edges[i].second);
      }
    }
  }
}

void bfs(int start){
  q.push(start);
  fr (i, n){
    disc[i] = false;
    dp[i] = 0;
    tagged[i] = false;
  }
  disc[start] = true;
  dp[start] = 1;
  bool change = false;
  int change_val = -1;
  while (!q.empty()){
    int cur = q.front(); bool add = false;
    q.pop();
    if (in_deg[cur] == 0){
      f (i, redges_start[cur], redges_end[cur]){
	if (dp[redges[i].second] == -1){
	  dp[cur] = -1;
	  break;
	}
	dp[cur] += dp[redges[i].second];
	dp[cur] %= mod;
      }
      add = true;
      change = true;
      if (tagged[cur] && change_val == cur){
	change_val = -1;
	change = false;
      }
      if (cur == n - 1)
	break;
    } else {
      if (tagged[cur]){
	if (!change && change_val == cur){
	  dp[cur] = -1;
	  add = true;
	  change = false;
	  change_val = -1;
	}
	q.push(cur);
      } else {
	tagged[cur] = true;
	if (change_val == -1){
	  change_val = 1;
	  change = false;
	}
	q.push(cur);
      }
    }

    if (add){
      f (i, edges_start[cur], edges_end[cur]){
	in_deg[edges[i].second]--;
	if (!disc[edges[i].second]) {
	  disc[edges[i].second] = true;
	  q.push(edges[i].second);
	}
      }
    }
  }
}

int main(){
  s(n); s(m);
  fr (i, m){
    s(edges[i].first); edges[i].first--;
    s(edges[i].second); edges[i].second--;
    redges[i].first = edges[i].second;
    redges[i].second = edges[i].first;
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

  sort(redges, redges + m, comp);
  redges_start[0] = 0;
  cur = 0;
  fr (i, m){
    while (cur != redges[i].first){
      redges_end[cur] = i;
      cur++;
      redges_start[cur] = i;
    }
  }
  redges_end[cur] = m;
  f (i, cur + 1, n){
    redges_start[i] = m;
    redges_end[i] = m;
  }
  // running the main bfs
  bfs_pre(0);  
  bfs(0);
  // printing the output
  if (dp[n - 1] == -1){
    printf("INFINITE PATHS\n");
  } else {
    printf("%lld\n", dp[n - 1]);
  }
  return 0;
}

