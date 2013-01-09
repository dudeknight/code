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


int a[][4] = {{3, 4, 12, 11}, {1, 2, 10, 9}, {5, 6, 14, 13}, {7, 8, 16, 15}};

ll bs[50];

int main(){
  map<ll, int> mp;
  map<ll, int>::iterator it;
  map<ll, int> mpx;
  mp[0] = 0;
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


  fr (i, cur){
    mp[bs[i]] = 1;
  }

  fr (i, cur){
    f (j, i + 1, cur){
      ll x = (bs[i] ^ bs[j]);
      it = mp.find(x);
      if (it == mp.end()){
	mp[x] = 2;
      } else {
	it = mpx.find(x);
	if (it == mpx.end()){
	  mpx[x] = 1;
	} else {
	  it->second++;
	}
      }
    }
  }

  /*
  cout << "mps " << mpx.size() << endl;
  for (it = mpx.begin(); it != mpx.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
  */


  fr (i, cur){
    f (j, i + 1, cur){
      f (k, j + 1, cur){
	ll x = (bs[i] ^ bs[j]) ^ bs[k];
	it = mp.find(x);
	if (it == mp.end()){
	  mp[x] = 3;
	}
      }
    }
  }

  int t, x;
  int inp_arr[16];
  ll out = ((((1L) << 8) - 1) << 8);
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
    inp = inp ^ out;
    it = mp.find(inp);
    if (it == mp.end()){
      printf("Case #%d: more\n", cs);
    } else {
      if (it->second == 2){
	if (mpx.find(inp) != mpx.end()){
	  printf("Case #%d: %d\n", cs, it->second);
	} else {
	  printf("Case #%d: more\n", cs);
	}
      }
    }    
  }
  return 0;
}
