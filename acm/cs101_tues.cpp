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

#define s(x) cin >> x
#define sll(x) cin >> x
#define sf(x) cin >> x
#define ss(x) cin >> x

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


bool search (int x, int n, int *a){
  int* it = lower_bound(a, a + n, x);
  if ( (*it) == x){
    return true;
  } else {
    return false;
  }
}


int main(){
  int a[100];
  int n;
  s(n);
  fr (i, n){
    s(a[i]);
  } 
  sort(a, a + n);
  int q, x;
  s(q);
  while (q--){
    s(x);
    if (search(x, n, a)){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}

