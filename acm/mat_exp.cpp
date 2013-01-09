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

#define size xx

ll mod = 1000000007L;
 
ll mat1[size][size];
ll mat2[size][size];
ll tmp[size][size];
ll resm[size][size];

int dn;
// dn is the dimension of the matrix
void init(){
  
  // resm should be intialized to the identity
  // mat1 should be intialized to the  matrix which has to be exponentiated  
}
 
void equalize(int x){
  if (x == 0) {
    fr (i, dn){
      fr (j, dn){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (x == 1){
    fr (i, dn){
      fr (j, dn){
	mat2[i][j] = resm[i][j];
      }
    }
  }
}
 
void multiply(int p){
  fr (i, dn){
    fr (j, dn){
      tmp[i][j] = 0;
      fr(k, dn){
	ll x = (mat1[i][k] * mat2[k][j]) % mod;
	tmp[i][j] += x;
	tmp[i][j] %= mod;
      }
    }
  }
  
  if (p == 0){
    fr (i, dn){
      fr (j, dn){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (p == 1){
    fr (i, dn){
      fr (j, dn){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}
 
void raise(ll np){
  init();
  ll cur_pow = np;
  while (cur_pow){
    if (cur_pow & 1){
      equalize(1);
      multiply(1);
    }
    equalize(0);
    multiply(0);
    cur_pow = cur_pow >> 1;
  }
}
 
int main(){
  return 0;
}
