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
  int t;
  cin >> t;
  string s;
  cin >> s;  
  char cur = s[0];
  int res = 0, res_temp = 1;
  f (i, 1, s.size()){
    if (s[i] == cur){
      res_temp++;
    } else {
      res += (res_temp - 1);
      cur = s[i];
      res_temp = 1;
    }
  }
  res += (res_temp - 1);
  cout << res << endl;
  return 0;
}
