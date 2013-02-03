/*
ID: dvdeepa1
PROG: checker
LANG: C++
*/
// written  by lonerdude (dvdreddy)
// all rights reserved
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream>
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

// #define fi cin
// #define fo cout

int n;
int a[14], tmpa[14], tmpb[14];
int diag1[35], diag2[35];
int usd_up[14]; int dc;
int sol[3][14]; int sol_cnt = 0;

void process_sol(){
  if (sol_cnt < 3){
    fr (i, n){
      sol[sol_cnt][i] = a[i];
    }
  }
  sol_cnt++;
}

bool check_diag(int i, int j){
  int d1 = i - j + n - 1;
  int d2 = i + j;
  if (diag1[d1] || diag2[d2]){
    return false;
  } else {
    return true;
  }
}


void block_diag(int i, int j){
  int d1 = i - j + n - 1;
  int d2 = i + j;
  diag1[d1] = 1; diag2[d2] = 1;
}

void unblock_diag(int i, int j){
  int d1 = i - j + n - 1;
  int d2 = i + j;
  diag1[d1] = 0; diag2[d2] = 0;  
}

void rec(int k){
  if (k == n){
    process_sol(); return;
  }

  fr (i, n){
    if (!usd_up[i] && check_diag(k, i)){
      usd_up[i] = 1; block_diag(k, i);
      a[k] = i; rec(k + 1);
      usd_up[i] = 0; unblock_diag(k, i);
    }
  }
}

void init(){
  dc = 2 * n - 1;
  fr (i, n){
    usd_up[i] = 0;
  }
  fr (i, dc){
    diag1[i] = 0;
    diag2[i] = 0;
  }
  fr (i, n){
    a[0] = i;
    usd_up[i] = 1; block_diag(0, i);
    rec(1);
    usd_up[i] = 0; unblock_diag(0, i);
  }  
}


int main(){

  fstream fi("checker.in",fstream::in);
  fi >> n;
  init();
  

    fi.close();
    fstream fo("checker.out",fstream::out);	

  fr (i, 3){
    fr (j, n){
      if (j){
	fo << " ";
      }
      fo << sol[i][j] + 1;
    }
    fo << endl;
  }
  fo << sol_cnt << endl;
  fo.close();
  
  return 0;
}



