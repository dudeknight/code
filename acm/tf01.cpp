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

int main(){
  int t;
  s(t);
  bool a[2][1010];
  int max_size = 1010;
  while (t--){
    int n, k;
    s(n); s(k);
    fr (i, k + 1){
      a[0][i] = 0; a[1][i] = 0;
    }
    int cur = 0;
    a[0][0] = 1; a[1][0] = 1;
    while (n--){
      int x; s(x);
      fr (i, k - x + 1){
	a[cur ^ 1][i + x] |= a[cur][i];
      }
      
      fr (i, k + 1){
	a[cur][i] = a[cur ^ 1][i];
      }
      cur = cur ^ 1;
    }
    cout << ((int) a[0][k]) << endl;    
  }
  return 0;
}
