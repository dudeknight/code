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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  ll  y, k, n;
  cin >> y >> k >> n;
  ll rem = y % k;
  ll remx = k - (rem);
  remx %= k;
  ll rng = n - y;
  ll rngrem = rng % k;
  ll cnt = rng / k;

  if (remx <= rngrem && rng >= 0){
    cnt++;
  }

  if (remx == 0){
    cnt--;
  }
  if (cnt <= 0) {
    printf("-1\n");
  } else {
    int strt = remx;
    if (remx == 0){
      strt = k;
    }
    while (strt <= n - y){
      printf("%d ",strt);
      strt += k;
    }
    cout << endl;
  }


  return 0;
}
