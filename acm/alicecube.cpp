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
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<ll, int> pil;

int a[][4] = {{3, 4, 12, 11}, {1, 2, 10, 9}, {5, 6, 14, 13}, {7, 8, 16, 15}};

ll bs[50];

int main(){
  map<ll, int> mp;
  map<ll, int>::iterator it;
  map<ll, int> mpx;

  int cur = 0;
  fr (i, 4){
    fr (j, 4){
      bs[cur] = (1L << (a[i][j] - 1)) + (1L << (a[i][(j + 1) % 4] - 1));
      cur++;
    }
  }
  fr (i, 4){
    fr (j, 4){
      bs[cur] = (1L << (a[i][j] - 1)) + (1L << (a[(i + 1) % 4][j] - 1));
      cur++;
    }
  }
  ll out = ((((1L) << 8) - 1) << 8); 
  mp[out] = 0;
  queue<pil> q;
  q.push(pil(out, 0));
 
  while (!q.empty()){
    pil px = q.front();
    q.pop();
    fr (i, cur){
      ll y = px.first & bs[i];
      if (y != 0 && (y & (y - 1)) == 0){
	ll res = px.first ^ bs[i];
	it = mp.find(res);
	if (it == mp.end()){
	  mp[res] = px.second + 1;
	  if (px.second < 2){
	    q.push(pil(res, px.second + 1));
	  }
	}
      }
    }       
  }

  /*
  cout << mp.size() << endl;
  for (it = mp.begin(); it != mp.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
  */
  

  int t, x;
  int inp_arr[16];

  si(t);
  f (cs, 1, t + 1){
    ll inp = 0;
    fr (i, 16){
      si(inp_arr[15 - i]);
    }
    
    fr (i, 16){
      inp <<= 1;
      inp += inp_arr[i];
    }
    ll inpt  = inp;
    it = mp.find(inp);
    if (it == mp.end()){
      printf("Case #%d: more\n", cs);
    } else {      
      printf("Case #%d: %d\n", cs, it->second);
    }    
  }
  return 0;
}
