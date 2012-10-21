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

int a[1000001];

int max_size = 1000001;

ll mod = 1073741824;

int main(){

  fr (i, max_size){
    a[i] = 0;
  }

  f (i, 1, max_size){
    for (int j = 0; j < max_size; j += i){
      a[j] += 1;
    }
  }


  int ax, b, c;
  cin >> ax >> b >> c;
  ll res = 0;
  f (i, 1, ax + 1){
    f (j, 1, b + 1){
      f (k, 1, c + 1){
	res += a[i * j * k];
	res %= mod;
      }
    }
  }
  
  cout << res << endl;
  return 0;

}
