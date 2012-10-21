#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int maxn = 100000, maxm = 100000;

vector <pair<int, int> > edges[maxn];
vector <int> times[maxn];

int dist[maxn];

struct compar{
  bool operator ()(int v1, int v2) const{
    if (dist[v1] != dist[v2]) {
      return dist[v1] < dist[v2];
    }
    else {
      return v1 < v2;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m; cin >> n >> m;

  for (int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    edges[a-1].push_back(make_pair(b-1, c));
    edges[b-1].push_back(make_pair(a-1, c));
  }
  for (int i = 0; i < n; i++){
    int k; cin >> k;
    
    times[i].resize(k);
    for (int j = 0; j < k; j++){
      cin >> times[i][j];
    }
  }

  fill_n(dist+1, n-1, INT_MAX);

  set<int, compar> q;
  for (int i = 0; i < n; i++){
    q.insert(i);
  }

  while (!q.empty()){
    int v = *q.begin(); q.erase(q.begin());
    if (v == n-1 || dist[v] == INT_MAX){
      break;
    }

    vector<int>::const_iterator ti(lower_bound(times[v].begin(), 
					       times[v].end(), 
					       dist[v]));

    while (ti != times[v].end() && dist[v] == *ti){
      dist[v]++;
      ++ti;
    }
    
    for (int i = 0; i < (int)edges[v].size(); i++){
      const pair<int, int>& p = edges[v][i];
      
      set<int, compar>::iterator qi(q.find(p.first));
      if (qi != q.end()) {
	if (dist[v] + p.second < dist[p.first]){
	  q.erase(qi);
	  dist[p.first] = dist[v] + p.second;
	  q.insert(p.first);
	}
      }
    }
  }
  
  cout << (dist[n-1] < INT_MAX ? dist[n-1] : -1) << '\n';
}
