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
bool a[10000];

int main(int argc, char *argv[]) {
  int t, n;
  string x;
  s(t);
  while (t--){
    s(n);
    fr (i, n){
      a[i] = true;
    }
    cin >> x;
    fr (i, n){
      if (x[i] == '1'){
	a[i] = false;
	if (i){
	  a[i - 1]  = false;
	} 
	
	if (i < n - 1){
	  a[i + 1] = false;
	}
      }
    }
    int res = 0;
    fr (i, n){
      if (a[i]){
	res++;
      }
    }
    printf("%d\n",res);

  }
  return 0;
}
