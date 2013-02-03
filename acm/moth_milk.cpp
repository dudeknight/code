/*
ID: dvdeepa1
PROG: milk3
LANG: C++
*/
// written  by lonerdude (dvdreddy)
// all rights reserved
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

// #define fi cin
// #define fo cout

int ma[3];


struct st{
  int a, b, c;
};


int main(){
  vector<int> res;
  queue<st> q;
  int dp[21][21][21];
  fr (i, 21){
    fr (j, 21){
      fr (k, 21){
	dp[i][j][k] = 0;
      }
    }
  }

  fstream fi("milk3.in",fstream::in);
  fi >> ma[0] >> ma[1] >> ma[2];  
  st x; x.a = 0; x.b = 0; x.c = ma[2];
  dp[0][0][ma[2]] = 1; q.push(x); int a[3], b[3];

  while (!q.empty()){
    st tmp = q.front(); q.pop();
    a[0] = tmp.a; a[1] = tmp.b; a[2] = tmp.c;
    if (tmp.a == 0){
      res.push_back(tmp.c);
    }
    // cout << "ffff " << a[0] << " " << a[1] << " " << a[2] << endl;
    fr (i, 3){
      fr (j, 3){
	if (i != j){
	  fr (k, 3){
	    b[k] = a[k];
	  }
	  b[j] += b[i];
	  if (b[j] > ma[j]){
	    b[i] = b[j] - ma[j]; b[j] = ma[j];
	  } else {
	    b[i] = 0;
	  }
	  // cout << b[0] << " " << b[1] << " " << b[2] << endl;
	  if (!dp[b[0]][b[1]][b[2]]){
	    st x; x.a = b[0]; x.b = b[1]; x.c = b[2];
	    dp[b[0]][b[1]][b[2]] = 1; q.push(x);
	  }
	}
      }
    }
  }
  
  sort(res.begin(), res.end());
  

  fi.close();
  fstream fo("milk3.out",fstream::out);	
    
  fr (i, res.size()){
    if (i){
      fo << " ";
    }
    fo << res[i];
  }
  fo << endl;
  fo.close();
  
  return 0;
}



