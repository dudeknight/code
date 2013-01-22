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
  string s;
  cin >> s;
  int n = s.size();  
  int res[n];
  int cur = 0;
  int end = n - 1;
  fr (i, n){
    if (s[i] == 'l'){
      res[end] = i + 1;
      end--;
    } else {
      res[cur] = i + 1;
      cur++;
    }
  }

  fr (i, n){
    printf("%d\n", res[i]);
  }
 
  return 0;
}
