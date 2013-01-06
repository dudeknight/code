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

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<int, int> pi;

pi extended_gcd(int a, int b){
  if (b == 0){
    return pi(1, 0);
  } else {
    q = a / b;
    r = a % b;
    pi st = extended_gcd(b, r);
    return pi(t, st.first - q * st.second);
  }
}

int mod = 142857;

int fast_exp_27(int x, int p){
  int res = 1;
  while (p){
    if (p & 1){
      res = res * x;
      res %= 27;
    }
    x *= x;
    x %= 27;
    p >>= 1;
  }
  return res;
}

int b_coeff[4][38][38];

int prim[] = {27, 11, 13, 37};

void init_binom(){
  fr (p, 4){
    fr (i, 38){
      fr (j, 38){
	b_coeff[p][i][j] = 0;
      }
    }
    fr (i, 38){
      b_coeff[p][i][0] = 1;
    }
  }

  fr (p, 4){
    f (i, 1, 38){
      f (j, 1, i){
	b_coeff[p][i][j] = b_coeff[p][i - 1][j] + b_coeff[p][i - 1][j - 1];
	b_coeff[p][i][j] %= prim[p];
      }
    }
  }


  

}



int main(){
  pi ex1 = extended_gcd(mod / 27, 27);
  pi ex2 = extenden_gcd(mod / 11, 11);
  pi ex3 = extended_gcd(mod / 13, 13);
  pi ex4 = extended_gcd(mod / 37, 37);

  int e[4];
  int e[0] = ex1.first * (mod / 27);
  int e[1] = ex2.first * (mod / 11);
  int e[2] = ex3.first * (mod / 13);
  int e[3] = ex4.first * (mod / 37);



  // lucas theorem for  11, 13, 37

  // expone for 13 

  


}


