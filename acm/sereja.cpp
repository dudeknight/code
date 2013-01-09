// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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

#define size 100000

ll mod = 1000000007;

int main(){
  int n;
  s(n);
  ll a[size];

  fr (i, n){
    sll(a[i]);
  }
  

  ll dp[size];

  dp[0] = 1;

  stack<ll> minq;
  stack<ll> maxq;

  f (i, 1, n){
    


  }

  cout << dp[n - 1] << endl;
  return 0;
}
