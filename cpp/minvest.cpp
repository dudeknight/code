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
#define size 50000

ll a[size];
ll bd[10];
ll pr[10];

int d, y;
ll amt;

void knpsack(){
  a[0] = 0;
  fr (i, size){
    a[i] = 0;
    fr (j, d){
      if (i - (bd[j]/1000) >= 0){
	a[i] = max(a[i], a[i - bd[j]/1000] + pr[j]);
      }
    }
    /*
    if (i < 15){
      cout << a[i] << " ";
    }
    */
  }
  // cout << endl;
}

int main(){
  int t;
  s(t);
  while (t--){
    sll(amt); s(y); s(d);
    fr (i, d){
      sll(bd[i]); sll(pr[i]);
    }
    knpsack();
    fr (i, y){
      amt += a[amt/1000];
    }
    printf("%lld\n", amt);
  }
  return 0;
}

