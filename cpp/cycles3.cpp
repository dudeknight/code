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
#define sll(x) scanf("%l64d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int k;
  s(k);
  int nx, tempn = 0;
  f (i, 3, 100){
    int x = (i * ((i - 1)* (i - 2) / 2)) / 3;
    if (x > k){
      nx = i  - 1;
      break;
    }
    tempn = x;
  }
  int y = k - tempn;
  
  int dp[100];
  int cnt = 0;
  while (y != 0){
    int tmpx = 0, ny;
    f (i, 1, nx + 1){
      int x = (i * (i + 1) / 2);
      if (x > y){
	ny = i;
	break;
      }
      tmpx = x;
    }
    dp[cnt] = ny;
    y = y - tmpx;
    cnt++;
  }

  int a[100][100];
  fr (i, 100){
    fr (j, 100){
      a[i][j] = 0;
    }
  }

  int n = nx + cnt;
  fr (i, nx){
    fr (j, nx){
      if (i != j){
	a[i][j] = 1;
      }
    }
  }
  
  fr (i, cnt){
    fr (j, dp[i]){
      a[j][nx + i] = 1;
      a[nx + i][j] = 1;
    }
  }

  cout << nx + cnt << endl;
  fr (i, nx + cnt){
    fr (j, nx + cnt){
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
