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

int main(int argc, char *argv[]) {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  while (t--){
    string x = s;
    fr (i, n - 1){
      if (s[i] == 'B' && s[i + 1] == 'G'){
	x[i] = 'G'; x[i + 1] = 'B';
      }
    }
    s = x;
  }
  cout << s << endl;
  return 0;
}
