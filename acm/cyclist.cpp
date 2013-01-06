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
#include <set>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


const int maxn = 100000, maxm = 100000;

vector <pair<int, float> > edges[maxn];
vector <int> times[maxn];

float dist[maxn];

struct compar{
  bool operator ()(int v1, int v2) const{
    if (dist[v1] != dist[v2]) {
      return dist[v1] > dist[v2];
    }
    else {
      return v1 < v2;
    }
  }
};

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t, n, m;
  int a, b;
  float cst;
  s(t);
  while (t--){

    s(n); m = 0;
    s(a); s(b); cin >> cst;
    fr (i, n){
      edges[i].clear();
    }
    while (a != -1 && b != -1){
      edges[a-1].push_back(make_pair(b-1, cst));
      edges[b-1].push_back(make_pair(a-1, cst));
      m++;
      s(a); s(b); cin >> cst;
    }

    dist[0] = 100.0;
    fill_n(dist+1, n, -1.0);
    set<int, compar> q;
    for (int i = 0; i < n; i++){
      q.insert(i);
    }

    while (!q.empty()){
      int v = *q.begin(); q.erase(q.begin());
      if (v == n-1 || dist[v] == -1.0){
	continue;
      }
    
      for (int i = 0; i < (int)edges[v].size(); i++){
	const pair<int, float>& p = edges[v][i];
      
	set<int, compar>::iterator qi(q.find(p.first));
	if (qi != q.end()) {
	  if (min(dist[v], p.second) > dist[p.first]){
	    q.erase(qi);
	    dist[p.first] = min(dist[v], p.second);
	    q.insert(p.first);
	  }
	}
      }
    }
    printf("%.8f\n", dist[n - 1]);
  }
}
