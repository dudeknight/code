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

#define size 500001
#define psize 1000001

bool chk[size];
ll primes[psize];
int prime_count;
// normal seive not super optimized

void do_seive(){
  fr (i, size){
    chk[i] = true;
  }
  
  ll m = (ll) sqrt(size) + 1;
  f (i, 2, m){
    if(chk[i]) {
      for(ll j = (2 * i * (i - 1)) + 1; j <= size; j += (2 * i - 1)){
	chk[j] = false;
      }
    }
  }

  primes[0] = 2;
  prime_count = 1;
  f (i, 2, size){
    if (chk[i]){
      primes[prime_count] = 2 * i - 1;
      prime_count++;
    }
  }
}

int main(){
  do_seive();
  fr (i, 20){
    cout << primes[i] << endl;
  }

  return 0;
}
