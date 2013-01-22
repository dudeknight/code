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

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

struct mvx{
  int x, y, z;
};

mvx mv[10001]; int xcnt = 0;

  set<int> sx[10001];  
int main(){
  int n; cin >> n;
  fr (i, n - 1){
    int x; int y; cin >> x >> y; x--; y--;
    sx[x].insert(y);;
  }
  
  fr (i, n - 1){    
    f (j, i + 1, n){
      if (sx[i].size() > sx[j].size()){
	set<int> temp = sx[j];
	sx[j] = sx[i]; sx[i] = temp;
	mv[xcnt].x = 1; mv[xcnt].y = i + 1; mv[xcnt].z = j + 1; xcnt++;
      }
    }
  }
  
  int cnt = 0;
  fr (i, n){
    if (sx[i].size() == 0) continue;
    
    set<int>::iterator it, jt, kt;

    for (it = sx[i].begin(); it != sx[i].end(); it++){
      if ((*it) <= cnt){
	if ((*it) == cnt) cnt++;
	continue;
      } else {
	mv[xcnt].x = 2; mv[xcnt].y = (*it) + 1; mv[xcnt].z = cnt + 1; xcnt++;
	
	f (j, i + 1, n){
	  jt = sx[j].find((*it));
	  kt = sx[j].find(cnt);
	  
	  if (jt != sx[j].end() && kt != sx[j].end()){
	    continue;
	  } else if (jt != sx[j].end()){
	    sx[j].erase(jt); 
	    sx[j].insert(cnt);
	  } else if (kt != sx[j].end()){
	    sx[j].erase(kt); 
	    sx[j].insert((*it));
	  } else {
	    continue;
	  }
	 
	}
	
      }
      cnt++;
    }

  }
  
  cout << xcnt << endl;
  fr (i, xcnt){
    printf("%d %d %d\n", mv[i].x, mv[i].y, mv[i].z);
  }

  return 0;
}
