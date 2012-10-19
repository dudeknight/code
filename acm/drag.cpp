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

#define s(x) cin >> x;
#define sf(x) cin >> x;
#define ss(x) cin >> x;

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<int, int> pi;


bool comp(pi x, pi y){
  int temp1 = x.second - x.first;
  int temp2 = y.second - y.first;
  if (temp1 >= 0 && temp2 >= 0){
    if (x.first == y.first){
      return (x.second > y.second);
    } else {
      return (x.first < y.first);
    }
  } else if (temp1 < 0 && temp2 >= 0){
    return true;
  } else if (temp1 >= 0 && temp2 < 0){
    return false;
  } else {
    return (x.second > y.second);
  }
}

int main(){
  pi a[1000];
  int st, n;
  s(st); s(n);
  fr (i, n){
    s(a[i].first); 
    s(a[i].second);
  }

  sort(a, a + n);


  int tempn = n;
  for (int i = 0; i < n; i++){
    if (st <= a[i].first){
      printf("NO\n");
      return 0;
    }
    st = st + a[i].second;
  }
  printf("YES\n");
  return 0;
}
