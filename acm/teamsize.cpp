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

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<int, int> pi;

ll modi = (ll) 1 << 30;

ll mod = 1000000007;

ll ax[500010];
int dp[500010];

ll q1[500010]; int q1strt, q1end; int q1sz;
ll q2[500010]; int q2strt, q2end; int q2sz;


map<int, int> m;

int main(){
  int t;
  int n, q; ll c, a, b, d;
  int x;
  s(t);
  while (t--){
    m.clear();
    s(n); sll(c); s(q); sll(a); sll(b); sll(d);
    int x = min(n, 10000);
    //  cout << "x " << x << endl;
    fr (i, x){
      sll(ax[i]);
    }
    f (i, x, n){
      ll y;
      y = ((ll)(a * ax[i - 1])) % modi + ((ll) (b * ax[i - 2])) % modi + d;
      y %= modi;
      ax[i] = y;
    }

    fr (i, n + 1){
      dp[i] = 0;
    }

    q1strt = 0; q2strt = 0;
    q1end = 1; q2end = 1;
    
    q1[0] = ax[0]; q1sz = 1;
    q2[0] = ax[0]; q2sz = 1;
    int cur = 0;
    f (i, 1, n){
      if (ax[i] < q1[q1strt]){
	if (q2[q2strt] - ax[i] <= c){
	  q1sz = 1; q2sz++;
	  q1[0] = ax[i]; q2[q2end] = ax[i];
	  q1strt = 0; q2end++;
	  q1end = 1;
	} else {
	  q1sz = 1; q2sz++;
	  q1[0] = ax[i]; q2[q2end] = ax[i];
	  q1strt = 0; q2end++;
	  q1end = 1;
	  while (q2[q2strt] - q1[0] > c){
	    if (ax[cur] == q2[q2strt]){
	      q2strt++; q2sz--;
	    } 
	    dp[i - cur]++;
	    cur++;
	  }
	}
      } else if (ax[i] > q2[q2strt]){
	if (ax[i] - q1[q1strt] <= c){
	  q2sz = 1; q1sz++;
	  q2[0] = ax[i]; q1[q1end] = ax[i];
	  q2strt = 0; q1end++;
	  q2end = 1;
	} else {
	  q2sz = 1; q1sz++;
	  q2[0] = ax[i]; q1[q1end] = ax[i];
	  q2strt = 0; q1end++;
	  q2end = 1;
	  while (q2[0] - q1[q1strt] > c){
	    if (ax[cur] == q1[q1strt]){
	      q1strt++; q1sz--;
	    }
	    dp[i - cur]++;
	    cur++;
	  }
	}
      } else {
	while (q1[q1end - 1] > ax[i]){
	  q1sz--;
	  q1end--;
	}
	q1[q1end] = ax[i]; q1sz++; q1end++;

	while (q2[q2end - 1] < ax[0]){
	  q2sz--;
	  q2end--;
	}
	q2[q2end] = ax[i]; q2sz++; q2end++;
      }
    }
    
    while (cur < n){
      dp[n - cur]++;
      cur++;
    }
    /*
    fr (i, n){
      cout << dp[i] << " "; 
    }
    */
    // cout << endl;
    int res = 0;
    map<int, int>::iterator it;
    for (int i = n; i > 0; i--){
      res = res + dp[i];
      it = m.find(res);
      if (it != m.end()){
	it->second = i;
      } else {
	m[res] = i;
      }
    }
    /*
    for (it = m.begin(); it != m.end(); it++){
      cout <<"m " << it->first << " " << it->second << endl;
    }
    */    

    int mx;
    while (q--){
      s(mx);
      it = m.upper_bound(mx); it--;
      printf("%d %d\n", it->second, it->first);
    }    
  }
  return 0;
}
