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

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  int t;
  si(t);
  while (t--){
    int x, y, z;
    si(x); si(y); si(z);
    double p;
    if (x > z + y){
      p = x - z - y;
    } else if (y > z + x){
      p = y - z - x;
    } else {
      p = max(0.00, (z - x - y) * 1.000);
    }
    printf("%.10f\n", p);
  }

}
