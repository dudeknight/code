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
#define sc(x) scanf("%c",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int MAX = 100000;

int a[100][10000];
int b[100][10000];

int main(){
  int n, m;
  s(n); s(m);
  string st;
  fr (i, n){
    cin >> st;
    fr (j, m){
      a[i][j] = st[j] - '0';
      b[i][j] = MAX;
    }   
  }

  fr (i, n){
    fr (j, m){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j) {
	b[i][j] = min(b[i][j], b[i][j - 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][m - 1] + 1);
      }
    }

    fr (j, m){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j) {
	b[i][j] = min(b[i][j], b[i][j - 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][m - 1] + 1);
      }
    }


    for (int j = m - 1; j >= 0; j--){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j < m - 1) {
	b[i][j] = min(b[i][j], b[i][j + 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][0] + 1);
      }
    }

    for (int j = m - 1; j >= 0; j--){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j < m - 1) {
	b[i][j] = min(b[i][j], b[i][j + 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][0] + 1);
      }
    }

    fr (j, m){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j) {
	b[i][j] = min(b[i][j], b[i][j - 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][m - 1] + 1);
      }
    }

    fr (j, m){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j) {
	b[i][j] = min(b[i][j], b[i][j - 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][m - 1] + 1);
      }
    }

    for (int j = m - 1; j >= 0; j--){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j < m - 1) {
	b[i][j] = min(b[i][j], b[i][j + 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][0] + 1);
      }
    }

    for (int j = m - 1; j >= 0; j--){
      if (a[i][j] == 1){
	b[i][j] = 0;
      } else if (j < m - 1) {
	b[i][j] = min(b[i][j], b[i][j + 1] + 1);
      }	else {
	b[i][j] = min(b[i][j], b[i][0] + 1);
      }
    }
  }

  fr (i, n){
    bool v = true;
    fr (j, m){
      if (b[i][j] < MAX){
	v = false;
	break;
      }
    }
    if (v){
      printf("-1\n");
      return 0;
    }
  }

  int res = 10 * MAX;
  
  fr (j, m){
    int tempres = 0;
    fr (i, n){
      tempres += b[i][j];
    }    
    res = min(res, tempres);
  }

  printf("%d\n", res);

  return 0;
}
