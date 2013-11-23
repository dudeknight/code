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
 
typedef unsigned long long ll;
 
ll mod = 1000000007;
 
ll mat1[64][64];
ll mat2[64][64];
ll fact[64][64];
ll tmp[64][64];
ll resm[64][64]; 


int a;ll b;

int n;

void init(){
  n = 1 << a;
  int tmpa[a];
  int tmpb[a];
  fr (i, n){
    fr (j, n){
      int x = i ^ j;
      int y = i;
      fr (k, a){
	tmpa[k] = x % 2;
	tmpb[k] = y % 2;
	x /= 2;
	y /= 2;
      }
      bool flg = true;
      fr (k, a - 1){
	if (tmpa[k] == 0 && tmpa[k + 1] == 0 && tmpb[k] == tmpb[k + 1]){
	  flg = false;
	  break;
	}
      }     
      mat1[i][j] = (int) flg;
      if (i != j)
	resm[i][j] = 0;
      else 
	resm[i][i] = 1;
    }
  }
}
 
void equalize(int x){
  if (x == 0) {
    fr (i, n){
      fr (j, n){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (x == 1) {
    fr (i, n){
      fr (j, n){
	mat2[i][j] = fact[i][j];
      }
    }
  } else if (x == 2){
    fr (i, n){
      fr (j, n){
	mat2[i][j] = resm[i][j];
      }
    }
  }
}
 
void multiply(int p){
  fr (i, n){
    fr (j, n){
      tmp[i][j] = 0;
      fr(k, n){
	ll x = (mat1[i][k] * mat2[k][j]) % mod;
	tmp[i][j] += x;
	tmp[i][j] %= mod;
      }
    }
  }
  
  if (p == 1){
    fr (i, n){
      fr (j, n){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (p == 2){
    fr (i, n){
      fr (j, n){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}
 
void raise(ll x){
  ll  cur_pow = x;
  while (cur_pow){
    if (cur_pow & 1){
      equalize(2);
      multiply(2);
    }
    equalize(0);
    multiply(1);
    cur_pow = cur_pow >> 1;
  }
}
 
int main(){
  s(a); sll(b);
  init();

  raise(b - 1);
  ll res = 0;

  fr (i, n){
    fr (j, n){
      res += resm[i][j];
      res %= mod;
    }
  }
  printf("%lld\n", res);
  return 0;
}
