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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  string si;
  cin >> si;
  map<char, int> m;
  m.clear();
  fr (i, si.size()){
    m[si[i]] = 0;
  }
  int x = m.size();
  if (x % 2 == 0){
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }
  cout << endl;
  return 0;
}
