/*
ID: dvdeepa1
PROG: numtri
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

#define fi cin
#define fo cout

int main(){

  fstream fi("numtri.in",fstream::in);
  
  int a[1000][1000]; int dp[1000][1000]; int r;
  fi >> r;
  fr (i, r){
    fr (j, i + 1){
      fi >> a[i][j];
    }
  }
  
  fr (i, r - 1){
    fr (j, r - 1 - i){
      a[r - 2 - i][j] += max(a[r - 1 - i][j], a[r - 1 - i][j + 1]);
    }
  }
  

  fi.close();
  fstream fo("numtri.out",fstream::out);	

  fo << a[0][0] << endl;
  fo.close();
  
  return 0;
}



