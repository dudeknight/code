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

int a[1000][1000];
ll dp[1000];

int main(){
  int n;
  s(n);
  ll res1, res2, temp; int count = 1;
  while (n){
    res1 = 0;
    res2 = 0;
    fr (i, n){
      dp[i] = 0;
    }

    fr (i, n){
      fr (j, n){
	s(a[i][j]);
	res1 += a[i][j];
	dp[i] += a[i][j];
	dp[j] -= a[i][j];
      }
    }

    fr (i, n){
      if (dp[i] > 0){
	res2 += dp[i];
      }
    }
    printf("%d. %lld %lld", count, res1, res2);
    s(n);
    count++;
  }  
  return 0;
}


