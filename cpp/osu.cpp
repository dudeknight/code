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

double fwd[100000];
double bck[100000];

double prob[100000];

int main(){
  int n;
  s(n);
  fr (i, n){
    sf(prob[i]);
  }

  fwd[0] = prob[0];
  f (i, 1, n){
    fwd[i] = prob[i] * fwd[i - 1] + prob[i];
  }
  bck[n - 1] = prob[n - 1];
  
  for (int i = n - 2; i >= 0; i--){
    bck[i] = prob[i] * bck[i + 1] + prob[i];
  }

  double res = 0;
  fr (i, n){
    res += fwd[i] + bck[i] - prob[i];
  }
  
  printf("%.10f\n", res);
  return 0;

}
