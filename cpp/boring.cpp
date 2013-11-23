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


int a[10000];

int main(){
  int n;ll h;
  s(n); sll(h)
  fr (i, n){
    sll(a[i]);
  }
  sort(a, a + n);
  
  if (n == 2){
    cout << "1 1" << endl;
    return 0;
  }

  if (a[n - 1] + a[n - 2] >= a[0] + a[2] + h && a[0] + a[1])
  

}
