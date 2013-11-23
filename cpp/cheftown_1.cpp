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

#define size 400000
int a[size];
int mini[size];
int maxi[size];

int main(){
  int n, w;
  s(n); s(w);
  map<int, char> m;
  fr (i, n){
    s(a[i]);
  }
  mini[0] = a[0];
  maxi[0] = a[0];
  int cur_max = 0;
  int cur_min = 0;
  f (i, 1, w){
    while(cur_min >= 0 && mini[cur_min] > a[i]){
      cur_min--;
    }
    cur_min++;
    mini[cur_min] = a[i];
    
    while(cur_max >= 0 && maxi[cur_max] < a[i]){
      cur_max--;
    }
    cur_max++;
    maxi[cur_max] = a[i];
  }

  int st_min = 0;
  int st_max = 0;
  int res = 0;
  f (i, 1, n - w + 1){
    if (maxi[st_max] - mini[st_min] == w - 1){
      res++;
    }

    if (a[i - 1] == mini[st_min]){
      st_min++;
      if (st_min > cur_min){
	st_min = 0;
	cur_min = -1;
      }
    }
    if (a[i - 1] == maxi[st_max]){
      st_max++;
      if (st_max > cur_max){
	st_max = 0;
	cur_max = -1;
      }
    }

    while(cur_min >= st_min && mini[cur_min] > a[i + w - 1]){
      cur_min--;
    }
    cur_min++;
    mini[cur_min] = a[i + w - 1];
    
    while(cur_max >= st_max && maxi[cur_max] < a[i + w - 1]){
      cur_max--;
    }
    cur_max++;
    maxi[cur_max] = a[i + w - 1];
  }

  if (maxi[st_max] - mini[st_min] == w - 1){
    res++;
  }
  printf("%d\n", res);

  return 0;
}
