// written by lonerdude(dvdreddy)
// all rights reserved
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

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)
#define pb push_back
typedef long long ll;
typedef vector<int>  vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pi;

vvi edge;
vi cnt;

void update_cnt(int x, int par){
  if (edge[x].size() == 1){
    cnt[x] = 1;
  } else {
    fr (i, edge[x].size()){
      int y = edge[x][i];
      if (y != par){
	update_cnt(y, x); cnt[x] += cnt[y];
      }
    }
  }
}

int main(){
  int n, m;
  si(n); si(m);
  edge.resize(n);
  cnt.resize(n);

  fr (i, n - 1){
    int x, y;
    si(x); si(y); x--; y--;
    edge[x].pb(y); edge[y].pb(x);
  }

  int disc[n];
  queue<pi> q;

  bool tch[n]; int res[n];
  fr (i, n){
    tch[i] = false; res[i] = 0; cnt[i] = 0;
  }
  update_cnt(0, -1);

  fr (i, n){
    cout << cnt[i] << " " << endl;
  }

  fr (i, m){
    int x; int y; si(x); si(y); x--; y--;
    tch[x] = true; tch[y] = false;
  }

  int x = -1;
  if (tch[0]){
    x = cnt[0];
  }
  fr (i, n){
    disc[i] = 0;
  }
  q.push(pi(0, x)); disc[0] = 1; res[0] = (x == -1 ? 0 : x);


  while (!q.empty()){
    pi x = q.front(); q.pop();
    fr (i, edge[x.first].size()){
      if (!disc[edge[x.first][i]]){
	pi nw = pi(edge[x.first][i], x.second); res[nw.first] = res[x.first];
	if (tch[nw.first] && x.second == -1){
	  nw.second = cnt[nw.first]; res[nw.first] = nw.second;
	}
	disc[nw.first] = 1;
	q.push(nw);	
      }
    }
  }  

  fr (i, n){
    printf("%d ", res[i]);
  }
  printf("\n");
}
