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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int a[1000];
  int n, k;
  s(n); s(k);
  fr (i, 2 * n + 1){
    s(a[i]);
  }
  for (int i = 1; i < 2 * n + 1; i += 2){
    if (a[i] - 1 > a[i + 1] && a[i] - 1 > a[i - 1]){
      a[i]--;
      k--;
    }
    if (k == 0){
      break;
    }
  }
  
  fr (i, 2 * n + 1){
    if (i){
      printf(" ");
    }
    printf("%d",a[i]);
  }
  printf("\n");
  return 0;
}
