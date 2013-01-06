// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

map<int, int> m;

int main(){
  int n, mx;
  s(n); s(mx);
  int x;
  int a[n];
  fr (i, n){
    s(a[i]);
    m[a[i]] = 0;
  }
  int y;
  vector<vector<int> > v;
  v.resize(n);
  fr (i, mx){
    s(x); s(y); x--; y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  
  cout << "------- " << endl;
  set<int> st;
  set<int>::iterator sit;
  fr (i, n){
    st.clear();
    fr (j, v[i].size()){
      st.insert(a[v[i][j]]);
    }
    cout << "i " << i << " " << a[i] << "--------\n";
    for (sit = st.begin(); sit != st.end(); sit++){
      cout << *sit << " " ;
      if (*sit != a[i]){
	m[*sit]++;
      }
    }
    cout << endl;
  } 
  map<int, int>::iterator it;
  int mini = m.begin()->second;
  for (it = m.begin(); it != m.end(); it++){
    cout << it->first << " " << it->second << endl;
    mini = max(it->second, mini);
  }

  for (it = m.begin(); it != m.end(); it++){
    if (it->second == mini){
      cout << it->first << endl;
      return 0;
    }
  }
  return 0;
}
