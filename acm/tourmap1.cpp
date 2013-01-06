// written by lonerdude(dvdreddy)
// all rights reserved
// the template by dvdreddy
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



int result(string ct){
  int n = ct.size();
  int res = 0;
  fr (i, n - 1){
    res = res * 10 + (ct[i] - '0');
  }
  return res;
}


int main(){
  int t, n, cur;
  s(t);
  string a[5006], b[5003], cost[5002];
  map<string, int> ids;
  int lft[5002];
  int rt[5002];
  map<string, int>::iterator it;
  int st[5000];
  while (t--){
    s(n); n--;
    cur = 0;
    fr (i, n + 1){
      lft[i] = -1;
      rt[i] = -1;
    }
    int tot = 0;
    ids.clear();
    fr (i, n){
      cin >> a[i] >> b[i] >> cost[i];
      tot += result(cost[i]);
      it = ids.find(a[i]);
      if (it == ids.end()){
	ids[a[i]] = cur;
	lft[cur] = i;
	cur++;
      } else {
	lft[it->second] = i;
      }      
      it = ids.find(b[i]);
      if (it == ids.end()){
	ids[b[i]] = cur;
	rt[cur] = i;
	cur++;
      } else {
	rt[it->second] = i;
      }      
    }
    
    fr (i, n + 1){
      if (lft[i] == -1){
	cur = i;
	break;
      }
    }
    st[0] = cur;
    f (i, 1, n){
      cur = lft[ids[b[cur]]];
      st[i] = cur;
    }
    
        
    fr (i, n){
      cout << a[i] << " " << b[i] << " " << cost[i] << endl;
    }
    cout << tot << "$" << endl;
  }
  return 0;
}
