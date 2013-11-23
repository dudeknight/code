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
#define rf(i,a,b) for(int i=a-1;i>=b;i--)
#define rfr(i,n) rf(i,n,0)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int t, n;
  s(t);
  int  a[150][150];
  while (t--){
    s(n);
    fr (i, n){
      fr (j, n){
	s(a[i][j]);
      }
    }

    rf(i, n - 1, 0){
      a[i][n - 1] = a[i][n - 1] + a[i + 1][n - 1];
    }

    rf(i, n - 1, 0){
      a[n - 1][i] += a[n - 1][i + 1];
      rfr(j, n - 1){
	a[j][i] += max(a[j][i + 1], a[j + 1][i]);
      }
    }

    if (a[0][0] >= 0){
      float x = ((float)a[0][0])/(float) (2 * n - 3);
      printf("%.8f\n",x);
    } else {
      printf("Bad Judges\n");
    }
  }
  return 0;
}
