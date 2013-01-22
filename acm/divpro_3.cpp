// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
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

inline void spIntRead(int* a){
  char c = 0;
  while (c < 33) c = fgetc(stdin);
  *a = 0;
  while (c > 33){
    *a = *a * 10 + c - '0';
    c = fgetc(stdin);
  }
}

inline void spLLRead(ll* a){
  char c = 0;
  while (c < 33) c = fgetc(stdin);
  *a = 0L;
  ll x = (ll) 10;
  while (c > 33){
    *a = *a * x + (ll)(c - '0');
    c = fgetc(stdin);
  }
}

int maxs[] = {55, 37, 19, 19};

#define szsss 1304160

int val[][2] = {{0, 0}, {1, 0}, {0, 1}, 
		{2, 0}, {1, 1}, {3, 0}, {0, 2}};

int val57[][2] = {{1, 0}, {0, 1}};

ll dp_final[37][55][37][19][19];
ll dp_23[19][19][55][37];
ll dp_57[19][19][19][19];
ll dp_final2[37];

struct dpst{
  int a1, a2;
};

struct resst{
  int dig;
  int a1, a2;
};

bool operator<(const dpst& x, const dpst& y){
 
  if (x.a1 == y.a1){
    return (x.a2 < y.a2);
  } else {
    return (x.a1 < y.a1);
  }
}

bool operator<(const resst& x, const resst& y){
 
 if (x.dig == y.dig){
    if (x.a1 == y.a1){
      return (x.a2 < y.a2);
    } else {
      return (x.a1 < y.a1);
    }
  } else {
    return (x.dig < y.dig);
  }
}


ll mod = (((ll)1) << 32);
map<resst, ll> res;

void pre1(){
  ll binc[20][20];
  fr (i, 20){
    fr (j, 20){
      binc[i][j] = 0;
    }
    binc[i][0] = 1;
  }
  
  f (i, 1, 20){
    f (j, 1, i + 1){
      binc[i][j] = binc[i - 1][j - 1] + binc[i - 1][j];
      binc[i][j] %= mod;
    }
  }


  map<dpst, ll> mp[2];
  int cur = 0;
  dpst x;
  x.a1 = 0; x.a2 = 0;
  mp[0][x] = 1;
  resst xr; xr.a1 = 0; xr.a2 = 0; xr.dig = 0;
  res[xr] = 1;
  map<dpst, ll>::iterator it;

  f (i, 1, 19){
    for (it = mp[cur].begin(); it != mp[cur].end(); it++){
      dpst y = it->first;
      fr(p, 7){
	dpst yx = y;	
	yx.a1 += val[p][0]; yx.a2 += val[p][1];
	mp[cur ^ 1][yx] += it->second;
	mp[cur ^ 1][yx] %= mod;
      }
    }

    for (it = mp[cur ^ 1].begin(); it != mp[cur ^ 1].end(); it++){
      if (it->first.a1 >= 0 && it->first.a2 >= 0){
	resst y;
	y.a1 = it->first.a1; y.a2 = it->first.a2;
	y.dig = i;
	res[y] = it->second;
      }
    }

    mp[cur].clear();
    cur = cur ^ 1;
  }

  map<resst, ll>::iterator it1, it2;

  fr (i, 19){
    fr (j, 19){
      fr (k, maxs[0]){
	fr (p, maxs[1]){
	  dp_23[i][j][k][p] = 0;
	}
      }
    }
  }
  
  
  for (it1 = res.begin(); it1 != res.end(); it1++){
    for (it2 = res.begin(); it2 != res.end(); it2++){
      int x = it1->first.a1 - it2->first.a1; 
      int y = it1->first.a2 - it2->first.a2;
      if (x >= 0 && y>= 0){
	ll tmp = it1->second * it2->second;
	tmp %= mod;
	dp_23[it1->first.dig][it2->first.dig][x][y] = 
	  (dp_23[it1->first.dig][it2->first.dig][x][y] + tmp) % mod;
      }
    }
  }

  res.clear(); mp[0].clear(); mp[1].clear();
  cur = 0; x.a1 = 0; x.a2 = 0;
  mp[0][x] = 1;
  xr.a1 = 0; xr.a2 = 0; xr.dig = 0; res[xr] = 1;

  f (i, 1, 19){
    for (it = mp[cur].begin(); it != mp[cur].end(); it++){
      dpst y = it->first;
      fr(p, 2){
	dpst yx = y;	
	yx.a1 += val57[p][0]; yx.a2 += val57[p][1];
	mp[cur ^ 1][yx] += it->second;
	mp[cur ^ 1][yx] %= mod;
      }
    }

    for (it = mp[cur ^ 1].begin(); it != mp[cur ^ 1].end(); it++){
      if (it->first.a1 >= 0 && it->first.a2 >= 0){
	resst y;
	y.a1 = it->first.a1; y.a2 = it->first.a2;
	y.dig = i;
	res[y] = it->second;
      }
    }

    mp[cur].clear();
    cur = cur ^ 1;
  }

  fr (i, 19){
    fr (j, 19){
      fr (k, maxs[2]){
	fr (p, maxs[3]){
	  dp_57[i][j][k][p] = 0;
	}
      }
    }
  }
  
  for (it1 = res.begin(); it1 != res.end(); it1++){
    for (it2 = res.begin(); it2 != res.end(); it2++){
      int x = it1->first.a1 - it2->first.a1; 
      int y = it1->first.a2 - it2->first.a2;
      if (x >= 0 && y>= 0){
	ll tmp = it1->second * it2->second;
	tmp %= mod;
	dp_57[it1->first.dig][it2->first.dig][x][y] = 
	  (dp_57[it1->first.dig][it2->first.dig][x][y] + tmp) % mod;
      }
    }
  }

  
  f (i, 1, 37){
    int pdig = (i + 1) / 2;
    int ndig = (i / 2);	      
    fr (j1, maxs[0]){
      fr (j2, maxs[1]){
	fr (j3, maxs[2]){
	  fr (j4, maxs[3]){
	    ll* yx = &dp_final[i][j1][j2][j3][j4]; *yx = 0;
	    f (x, j3 + j4, pdig + 1){
	      ll y = binc[pdig][x] * binc[ndig][x - j3 - j4]; y %= mod;
	      y *= dp_57[x][x - j3 - j4][j3][j4]; y %= mod;
	      y *= dp_23[pdig - x][ndig - x + j3 + j4][j1][j2]; y %= mod;
	      *yx = (*yx + y) % mod;
	    }
	  }
	}
      }
    }
  }
}

void pre2(){
  dp_final2[1] = 0; dp_final2[2] = 0;
  
  ll nin = (ll) 9; ll tn = (ll) 10;

  ll temp1 = nin;
  ll temp2 = nin;

  f (i, 2, 37){
    if (i & 1){
      temp2 *= tn;
    } else {
      temp2 *= nin;      
    }
    temp2 %= mod; temp1 *= nin; temp1 %= mod;
    dp_final2[i] = (temp2 - temp1 + mod) % mod;
  }
}


int main(){
  pre1();
  pre2();
  //  return 0; 
  int t; si(t);
  int n; ll v;
  int ax[4]; ll temp;
  ll val_mult[] = {(ll) 2, (ll) 3, (ll) 5, (ll) 7};
  bool bx;
  while (t--){
    si(n); sll(v);
    bx = false;    
    if (v){
      fr (i, 4){
	ax[i] = 0; temp = val_mult[i];
	while (v % temp == 0){
	  v /= temp; ax[i]++;
	}
	if (ax[i] >= maxs[i]){
	  bx = true; break;
	}
      }
      if (bx || v != 1){
	printf("0\n");
      } else {
	printf("%lld\n", dp_final[n][ax[0]][ax[1]][ax[2]][ax[3]]);
      }
    } else {
      printf("%lld\n", dp_final2[n]);
    }
  }
  
  return 0;
}
