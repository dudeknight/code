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
 
ll mod = 1000000007;

int mat_size = 4;
 
ll mat1[4][4];
ll mat2[4][4];
ll fact[4][4];
ll tmp[4][4];
ll resm[4][4]; 

ll res;
ll resi[] = {44, 18, 5, 3};

void init(){
  fr (i, mat_size){
    fr (j, mat_size){
      fact[i][j] = 0;
    }
  }
  
  fact[0][0] = 2; fact[0][1] = 1;
  fact[0][2] = 13; fact[0][3] = 8;
  fact[1][0] = 1; fact[1][1] = 1;
  fact[1][2] = 5; fact[1][3] = 3;

  fact[2][2] = 2; fact[2][3] = 1;
  fact[3][2] = 1; fact[3][3] = 1;
}
 
void raise(ll cur_pow){

  fr (i, mat_size){
    fr (j, mat_size){
      mat1[i][j]  = fact[i][j];
      resm[i][j] = 0;
    }
    resm[i][i] = 1;
  }
  
  while (cur_pow){
    if (cur_pow & 1){
      fr (i, mat_size){
	fr (j, mat_size){
	  tmp[i][j] = 0;
	  fr(k, mat_size){
	    ll x = (mat1[i][k] * resm[k][j]) % mod;
	    tmp[i][j] += x;
	    tmp[i][j] %= mod;
	  }
	}
      }
      fr (i, mat_size){
	fr (j, mat_size){
	resm[i][j] = tmp[i][j];
	}
      }      
    }
    if (cur_pow != 1){
      fr (i, mat_size){
	fr (j, mat_size){
	  tmp[i][j] = 0;
	  fr(k, mat_size){
	    ll x = (mat1[i][k] * mat1[k][j]) % mod;
	    tmp[i][j] += x;
	    tmp[i][j] %= mod;
	  }
	}
      }

      fr (i, mat_size){
	fr (j, mat_size){
	mat1[i][j] = tmp[i][j];
	}
      }      
    }
    cur_pow = cur_pow >> 1;
  }
}

 
int main(){
  init();
  int t; ll x;
  s(t);
  while (t--){
    sll(x);
    if (x == 3){
      printf("18\n"); continue;
    } else if (x == 2) {
      printf("5\n"); continue;
    } else if (x == 1){
      printf("0\n"); continue;
    } else if (x <= 0){
      printf("-1\n"); continue;
    }
    raise((x - 3) / 2);
    res = 0;
    fr (i, 4){
      res += resm[x % 2][i] * resi[i];
      res %= mod;
    }
    printf("%lld\n", res);
  }
  return 0;
}
