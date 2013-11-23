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

char c[2][20010];


int main(){
  int t;
  s(t);
  int a[2][5];
  char res[20010];
  int res7, res4;
  while (t--){
    cin >> c[0];
    cin >> c[1];
    int n = strlen(c[0]);
    fr (i, 2){
      fr (j, 5){
	a[i][j] = 0;
      } 
    }
    res7 = 0; res4 = 0;
    fr (k, 2){
      fr (i, n){
	if (c[k][i] < '4'){
	  a[k][0] += 1;
	} else if (c[k][i] == '4'){
	  a[k][1] += 1;
	} else if (c[k][i] < '7'){
	  a[k][2] += 1;
	} else if (c[k][i] == '7'){
	  a[k][3] += 1;
	} else{
	  a[k][4] += 1;
	}
      }
    }
    
    ll tmp = min(a[1][3], a[0][2]);
    res7 += tmp;
    a[0][2] -= tmp; a[1][3] -= tmp;
    tmp = min(a[1][3], a[0][0]);
    res7 += tmp;
    a[1][3] -= tmp; a[0][0] -= tmp;
    tmp = min(a[1][3], a[0][1]);
    res7 += tmp;
    a[1][3] -= tmp; a[0][1] -= tmp;

    tmp = min(a[0][3], a[1][2]);
    res7 += tmp;
    a[1][2] -= tmp; a[0][3] -= tmp;
    tmp = min(a[0][3], a[1][0]);
    res7 += tmp;
    a[0][3] -= tmp; a[1][0] -= tmp;
    tmp = min(a[0][3], a[1][1]);
    res7 += tmp;
    a[0][3] -= tmp; a[1][1] -= tmp;

    tmp = min(a[0][3], a[1][3]);
    res7 += tmp;
    a[0][3] -= tmp; a[1][3] -= tmp;


    tmp = min(a[1][1], a[0][0]);
    res4 += tmp;
    a[1][1] -= tmp; a[0][0] -= tmp;

    tmp = min(a[0][1], a[1][0]);
    res4 += tmp;
    a[0][1] -= tmp; a[1][0] -= tmp;

    tmp = min(a[0][1], a[1][1]);
    res4 += tmp;
    a[0][1] -= tmp; a[1][1] -= tmp;


    int cnt = 0;
    fr (i, res7){
      res[cnt] = '7';
      cnt++;
    }
    fr (i, res4){
      res[cnt] = '4';
      cnt++;
    }
    res[cnt] = '\0';
    printf("%s\n",res);

  }
  return 0;
}
