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
 
ll mat1[2][2];
ll mat2[2][2];
ll fact[2][2];
ll tmp[2][2];
ll resm[2][2]; 

void init(){
  mat1[0][0] = 2; resm[0][0] = 1;
  mat1[0][1] = 2; resm[0][1] = 0;
  mat1[1][0] = 1; resm[1][0] = 0;
  mat1[1][1] = 0; resm[1][1] = 1;
}
 
void equalize(int x){
  if (x == 0) {
    fr (i, 2){
      fr (j, 2){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (x == 1) {
    fr (i, 2){
      fr (j, 2){
	mat2[i][j] = fact[i][j];
      }
    }
  } else if (x == 2){
    fr (i, 2){
      fr (j, 2){
	mat2[i][j] = resm[i][j];
      }
    }
  }
}
 
void multiply(int x){
  fr (i, 2){
    fr (j, 2){
      tmp[i][j] = 0;
      fr(k, 2){
	ll x = (mat1[i][k] * mat2[k][j]) % mod;
	tmp[i][j] += x;
	tmp[i][j] %= mod;
      }
    }
  }
  
  if (x == 1){
    fr (i, 2){
      fr (j, 2){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (x == 2){
    fr (i, 2){
      fr (j, 2){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}
 
void raise(ll n){
  ll rsp = n - (ll)3;
  init();
  equalize(1);
  ll  cur_pow = rsp;
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
  fact[0][0] = (ll)2;
  fact[0][1] = (ll)2;
  fact[1][0] = (ll)1;
  fact[1][1] = (ll)0;
  
  int t; ll x; ll res;
  s(t); 
  if (t == 0){
    return 0;
  }
  while (t--){
    sll(x);
    if (x == 1) {
      printf("1\n");
      continue;
    } else if (x == 2) { 
      printf("3\n");
      continue;
    } else if (x == 3) {
      printf("8\n");
      continue;
    }
    raise(x);
    res = (resm[0][0] + resm[1][0]) * (ll)6 
      +  (resm[0][1] + resm[1][1]) * (ll) 2 ;
    res %= mod;
    printf("%lld\n",res);  
  }
  return 0;
}
