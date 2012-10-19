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

int mat_size = 3;
 
ll mat1[3][3];
ll mat2[3][3];
ll fact[3][3];
ll tmp[3][3];
ll resm[3][3]; 

ll res;
ll resi[] = {7, 4, 2};

void init(){
  fr (i, mat_size){
    fr (j, mat_size){
      fact[i][j] = 0;
    }
  }
  
  fact[0][0] = 1; fact[0][1] = 1;
  fact[0][2] = 1; 
  fact[1][0] = 1;
  fact[2][1] = 1;
}

ll fast_exp(ll x, ll p){ 
  ll res = 1;
  while (p){
    if (p & 1){
      res *= x;
      res %= mod;
    }
    x *= x;
    x %= mod;
    p >>= 1;
  }
  return res;
}

void multiply(int p){
  if (p == 1) {
    fr (i, mat_size){
      fr (j, mat_size){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (p == 2){
    fr (i, mat_size){
      fr (j, mat_size){
	mat2[i][j] = resm[i][j];
      }
    }
  }

  fr (i, mat_size){
    fr (j, mat_size){
      tmp[i][j] = 0;
      fr(k, mat_size){
	ll x = (mat1[i][k] * mat2[k][j]) % mod;
	tmp[i][j] += x;
	tmp[i][j] %= mod;
      }
    }
  }
  
  if (p == 1){
    fr (i, mat_size){
      fr (j, mat_size){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (p == 2){
    fr (i, mat_size){
      fr (j, mat_size){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}

void raise(ll p){

  fr (i, mat_size){
    fr (j, mat_size){
      mat1[i][j]  = fact[i][j];
      resm[i][j] = 0;
    }
    resm[i][i] = 1;
  }

  ll  cur_pow = p;
  while (cur_pow){
    if (cur_pow & 1){
      multiply(2);
    }
    multiply(1);
    cur_pow = cur_pow >> 1;
  }
}

int main(){
  init();
  int t; ll x;
  s(t);
  while (t--){
    sll(x);
    if (x <= 2){
      printf("0\n"); continue;
    }
    raise(x - 3);
    res = 0;
    fr (i, 3){
      res += resm[0][i] * resi[i];
      res %= mod;
    }
    res = fast_exp(2, x) + mod - res;
    res %= mod;
    printf("%lld\n", res);
  }
  return 0;
}
