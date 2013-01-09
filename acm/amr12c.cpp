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

ll x[50];
ll y[50];
double speed[50];
int n;

bool exist = false;

bool is_valid(double val){
  bool xi = false;
  if (val - 1.00 < 0.000){
    xi = true;
  }
  fr (i, n){
    f (j, i + 1, n){
      double scr = val * (speed[i] + speed[j]);
      ll scr2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      double scr3 = sqrt(scr2);
      if (xi){
	cout << "c1 " << val << endl;
	cout << i << " " << j << " " << scr << " " << scr3 << endl;
      }	
      if (scr < scr3){
	return false;
      }
    }
  }
  if (val < 0.5){
    exist = true;
  }
  return true;
}


int main(){
  int t;
  si(t);
  while (t--){
    si(n);
    fr (i, n){
      sll(x[i]); sll(y[i]); sf(speed[i]);
    }
    fr (i, n){
      cout << speed[i] << endl;
    }
    double lo = 0.0;
    double hi = 1000000.000;
    
    while (hi - lo > 0.00000001){
      double mid = (hi + lo) / 2;
      bool bxb = is_valid(mid);
      cout << "pi " << lo << " " << hi << " " << mid << " " << bxb << endl;
      if (exist){
	return 0;
      }
      if (!bxb){
	lo = mid;
      } else {
	hi = mid;
      }
    }    
    printf("%.10lf\n", hi);    
  }
  return 0;
}
