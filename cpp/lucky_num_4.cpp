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
#define c 1459
#define b 163
#define a 20

ll dp[a][b][c];
ll dp1[a][b][c];

bool seive[1500];
int prime[300];

int dig[18];

int cnt_prime = 0;
int cnt_sum = 0;

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
  int p_sum, p_sqr, p_sqr_h, p_sum_h;
  p_sum = 0;
  p_sqr = 0;
  int* temp;

  for (int i = cnt - 1; i > 0; i--){
    fr (p, dig[i]){
      res += dp1[i][cur_sum + p][cur_sqr + p * p];
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
  cout << cnt_sum << " " << prime[cnt_sum - 1] << endl;
  cout << cnt_prime << endl;

  
  fr (i, a){
    fr (j, b){
      fr (k, c){
	dp[i][j][k] = 0;
	dp1[i][j][k] = 0;
      }
    }
  }

  dp[0][0][0] = 1;
  int indi = 0;
  f (m, 1, 18){
    f (i, 0, 10){
      for (int j = 9 * m - i; j >= 0; j--){
	for (int k = 81 * m - i * i; k >= 0; k--){
	  dp[m][j + i][k + i * i] += dp[m - 1][j][k];
	}
      }
    }
  }

  f (m, 1, 18){
    f (p, 0, cnt_sum){
      f (q, p, cnt_prime){
	f (i, 0, min(9 * m,prime[p]) + 1){
	  f (j, 0, min(81 * m, prime[q]) + 1){
	    dp1[m][i][j] += dp[m][prime[p] - i][prime[q] - j];
	  }
	}
      }
    }    
  }
 
  /*
  int p_sum_l, p_sqr_l, p_sum_h, p_sqr_h;
  f (m, 1, 20){
    fr (i, 9 * m){
      f (j, i, 81 * m){
	int* temp = lower_bound(prime, prime + cnt_prime, i);
	p_sum_l =(int) (temp - prime);
	
	temp = lower_bound(prime, prime + cnt_prime, j);
	p_sqr_l =(int) (temp - prime);
	
	temp = upper_bound(prime, prime + cnt_prime, 9 * m + i);
	p_sum_h =(int) (temp - prime);

	temp = upper_bound(prime, prime + cnt_prime, 9 * 9 * m + j);
	p_sqr_h =(int) (temp - prime);
	ll cnt = 0;

	f (p, p_sum_l, p_sum_h){
	  f (q, p_sqr_l, p_sqr_h){
	    cnt += dp[m][prime[p] - i][prime[q] - j];
	  }
	}
	dp[m][i][j] = cnt;
      }
    }
  }
  */
  return 0;
  //cout << "start\n";
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
