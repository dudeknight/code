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

int mat_size;
 
ll mat1[50][50];
ll mat2[50][50];
ll fact[50][50];
ll tmp[50][50];
ll resm[50][50]; 

ll res[50];
ll init_set[50];

void init(){
  fr (i, mat_size){
    fr (j, mat_size){
      fact[i][j] = 0;
    }
  }
  fact[0][0] = 1;
  fact[0][1] = 1;
  fact[0][mat_size - 1] = 1;
  f (i, 1, mat_size - 1){
    fr(j, mat_size){
      fact[i][j] = fact[i - 1][j];
    }
    fact[i][i] += 1;
    fact[i][i + 1] += 1;
  }

  fr (j, mat_size){
    fact[mat_size - 1][j] = fact[mat_size - 2][j] + fact[0][j];
  }
  fact[mat_size - 1][mat_size - 1] += 1;
  
  fr (i, mat_size){
    fr (j, mat_size){
      mat1[i][j] = fact[i][j];
      resm[i][j] = 0; 
    }
    resm[i][i] = 1;
  }
}

void equalize(int x){
  if (x == 0) {
    fr (i, mat_size){
      fr (j, mat_size){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (x == 1) {
    fr (i, mat_size){
      fr (j, mat_size){
	mat2[i][j] = fact[i][j];
      }
    }
  } else if (x == 2){
    fr (i, mat_size){
      fr (j, mat_size){
	mat2[i][j] = resm[i][j];
      }
    }
  }
}
 
void multiply(int x){
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
  
  if (x == 1){
    fr (i, mat_size){
      fr (j, mat_size){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (x == 2){
    fr (i, mat_size){
      fr (j, mat_size){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}
 
void raise(ll p){
  init();
  equalize(1);
  ll  cur_pow = p;
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

void compute_res(int start, int p_res){
  fr (i, mat_size){
    tmp[0][i] = init_set[(i + start) % mat_size];
    tmp[0][i] %= mod;
  }
  
  fr (i, mat_size){
    tmp[1][i] = 0;
    fr (j, mat_size){
      tmp[1][i] += resm[i][j] * tmp[0][j];
      tmp[1][i] %= mod;
    }
  }
  
  fr (i, p_res){
    tmp[1][i] += tmp[1][i + 1] + tmp[1][((mat_size + i - 1) % mat_size)];
    tmp[1][i] %= mod;
  }
  
  fr (i, mat_size){
    res[(i + start) % mat_size] = tmp[1][i];
  }
}
 
int main(){
  
  int t; ll x;
  s(t);
  if (t == 0){
    return 0;
  }
  while (t--){
    sll(mat_size); sll(x);
    fr (i, mat_size){
      sll(init_set[i]);
    }
    raise(x/mat_size);
    int p_res = x % mat_size;
    fr (i, mat_size){
      compute_res(i, p_res);
      fr (j, mat_size){
	if (j){
	  printf(" ");
	}
	printf("%lld",res[j]);
      }
      printf("\n");
    }
    if (t){
      printf("\n");
    }
  }
  return 0;
}
