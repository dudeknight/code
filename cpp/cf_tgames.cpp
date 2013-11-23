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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  int c1[100], c2[100];
  int n; si(n);
  fr (i, n){
    si(c1[i]); si(c2[i]);
  }
  
  int res = 0;
  fr (i, n){
    fr (j, n){
      if (c1[i] == c2[j]){
	res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
