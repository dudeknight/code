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

map<int, set<int> > m;

int main(){
  int n, mx;
  s(n); s(mx);
  int x;
  int a[n];
  map<int, set<int> >::iterator it;
  int min_col = 344443;
  fr (i, n){
    s(a[i]);
    min_col = min(min_col, a[i]);
  }
  int y;
  fr (i, mx){
    s(x); s(y); x--; y--;
    if (a[x] != a[y]){
      m[a[x]].insert(a[y]);
      m[a[y]].insert(a[x]);
    }
  }
  
  int mini = (m.begin()->second).size();
  for (it = m.begin(); it != m.end(); it++){
    mini = max((int)(it->second).size(), mini);
  }

  for (it = m.begin(); it != m.end(); it++){
    if ((it->second).size() == mini){
      cout << it->first << endl;
      return 0;
    }
  }
  if (m.size() == 0){
    cout << min_col << endl;
  }
  return 0;
}
