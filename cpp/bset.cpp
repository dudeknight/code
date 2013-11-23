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
  int n, m; 
  si(n); si(m);
  int x = min(n, m);
  cout << x + 1 << endl;
  int cur_x = n; int cur_y = 0;
  cout << cur_x << " " << cur_y << endl;
  fr (i, x){
    cur_x--; cur_y++;
    cout << cur_x << " " << cur_y << endl;
  }
  return 0;
}
