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
  si(t)
  while (t--){
    bool b; 
    b = true;
    string s; cin >> s;
    int n = s.size();
    fr (i, n){
      if (s[i] != s[n - 1 - i]){
	b = false;
      }
    }
    if (b){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
