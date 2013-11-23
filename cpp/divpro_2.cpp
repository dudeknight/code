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

int maxs[] = {60, 38, 26, 22};

#define szsss 1304160

int val[][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0},
		{0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0},
		{0, 2, 0, 0}};

ll dp_res2[37];

struct dpst{
  int a1, a2, a3, a4;
};

struct resst{
  int dig;
  int a1, a2, a3, a4;
};

bool operator<(const dpst& x, const dpst& y){
 
  if (x.a1 == y.a1){
    if (x.a2 == y.a2){
      if (x.a3 == y.a3){
	return (x.a4 < y.a4);
      } else {
	return (x.a3 < y.a3);
      }
    } else {
      return (x.a2 < y.a2);
    }
  } else {
    return (x.a1 < y.a1);
  }

}

bool operator<(const resst& x, const resst& y){
  if (x.dig == y.dig){
    if (x.a1 == y.a1){
      if (x.a2 == y.a2){
	if (x.a3 == y.a3){
	  return (x.a4 < y.a4);
	} else {
	  return (x.a3 < y.a3);
	}
      } else {
	return (x.a2 < y.a2);
      }
    } else {
      return (x.a1 < y.a1);
    }
  } else {
    return (x.dig < y.dig);
  }
}


ll mod = (1LL << 32);
map<resst, ll> res;

void pre1(){
  map<dpst, ll> mp[2];
  int cur = 0;
  dpst x;
  x.a1 = 0; x.a2 = 0; x.a3 = 0; x.a4 = 0;
  mp[0][x] = 1;
  map<dpst, ll>::iterator it;

  fr (i, 19){
    cout << "dig " << i << " " << mp[cur].size() << endl;
    for (it = mp[cur].begin(); it != mp[cur].end(); it++){
      dpst y = it->first;
      fr(p, 9){
	dpst yx = y;	
	yx.a1 += val[p][0]; yx.a2 += val[p][1]; yx.a3 += val[p][2]; yx.a4 += val[p][3];
	mp[cur ^ 1][yx] += it->second;
	mp[cur ^ 1][yx] %= mod;
      }
    }

    for (it = mp[cur ^ 1].begin(); it != mp[cur ^ 1].end(); it++){
      if (it->first.a1 >= 0 && it->first.a2 >= 0 && it->first.a3 >= 0 && it->first.a4 >= 0){
	resst y;
	y.a1 = it->first.a1; y.a2 = it->first.a2; y.a3 = it->first.a3; y.a4 = it->first.a4;
	y.dig = i;
	res[y] = it->second;
      }
    }

    mp[cur].clear();
    cur = cur ^ 1;
  }
}

void pre2(){


  
}


int main(){
  pre1();
  pre2();
  return 0;
  int t;
  spIntRead(&t);
  int n; ll v;
  while (t--){
    //  spIntRead(&n); spLLRead(&v);
    printf("%lld\n",21123L);
  }
  
  return 0;
}
