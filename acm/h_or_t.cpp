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
typedef pair<int, int> pi;

int main(){
  int x, y, a, b;
  s(x); s(y); s(a); s(b);
  pi arr[10000];
  int cnt = 0;
  f (i, a, x + 1){
    f (j, b, y + 1){
      if (i > j){
	arr[cnt] = pi(i, j); cnt++;
      }
    }
  }
  cout << cnt << endl;
  fr (i, cnt){
    cout << arr[i].first << " " << arr[i].second << endl;
  }
}
