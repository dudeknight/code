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
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef map<pi, int> mi;

#define c 1459
#define b 163
#define a 20


bool seive[1500];
int prime[300];

int dig[18];

int cnt_prime = 0;
int cnt_sum = 0;

mi* dp;



ll luck(ll x){
  int cnt = 0;
  while (x){
    dig[cnt] = x % 10;
    cnt++;
    x = x / 10;
  }

  ll res = 0;
  int cur_sum = 0;
  int cur_sqr = 0;
  int p_sum_l,p_sum_h, p_sqr_l,p_sqr_h;

  int* temp;

  mi::iterator it;

  for (int i = cnt - 1; i > 0; i--){
    fr (p, dig[i]){
      int* temp = lower_bound(prime, prime + cnt_prime, cur_sum + p);
      p_sum_l =(int) (temp - prime);
      
      temp = lower_bound(prime, prime + cnt_prime, cur_sqr + p * p);
      p_sqr_l =(int) (temp - prime);

      it = dp[i].end(); it--;

      temp = upper_bound(prime, prime + cnt_prime, (it->first).first + cur_sum + p);
      p_sum_h =(int) (temp - prime);

      temp = upper_bound(prime, prime + cnt_prime, (it->first).second + cur_sqr + p * p);
      p_sqr_h =(int) (temp - prime);

      f (j, p_sum_l, p_sum_h){
	f (k, p_sqr_l, p_sqr_h){
	  pi px = pi(prime[j] - cur_sum - p, prime[k] - cur_sqr - p * p);
	  it = dp[i].find(px);
	  if (it != dp[i].end()){
	    res += it->second;
	  }
	}
      }
      //cout << i  << " " << p << " " << res << " " << cur_sum << " " << cur_sqr << endl;
    }

    cur_sum += dig[i];
    cur_sqr += dig[i] * dig[i];
  }

  for (int i = 0; i <= dig[0]; i++){
    if (seive[cur_sum + i] && seive[cur_sqr + i * i]){
      res++;
    }
  }

  return res;
}

int main(){
  
  fr (i, c){
    seive[i] = true;
  }
  
  seive[1] = false;
  seive[0] = false;
  cnt_prime = 0;

  f (i, 2, c){
    if (seive[i]){
      prime[cnt_prime] = i;
      cnt_prime++;
      for (int j = i * i; j < c; j += i){
	seive[j] = false;
      }
    }
  }

  int* temp = upper_bound(prime, prime + cnt_prime, 162);
  cnt_sum =(int) (temp - prime);
  //cout << cnt_sum << " " << prime[cnt_sum - 1] << endl;

  dp = new mi[20];
  mi tempm;
  dp[0][pi(0, 0)] = 1;
  mi::iterator it, jt;
  f (m, 1, 20){
    f (i, 0, 10){
      for (it = dp[m - 1].begin(); it != dp[m - 1].end(); it++){
	pi p = pi((it->first).first + i, (it->first).second + i * i);
	jt = dp[m].find(p);
	if (jt != dp[m].end()){
	  jt->second += it->second;
	} else {
	  dp[m][p] = it->second;
	}
      }
    }
  }
  

  int t;
  s(t);
  ll x, y;
  while (t--){
    sll(x); sll(y);
    // cout << y << " " << luck(y) << endl;
    // cout << x << " " << luck(x - 1) << endl;
    printf("%lld\n", luck(y) - luck(x - 1));
  }


  return 0;
}
