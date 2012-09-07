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

bool seive[1500];
int prime[300];

int dig[18];

int cnt_prime = 0;
int cnt_sum = 0;



ll luck1(int x){
  map<pi, int> m;???
  
  int cnt = 0;
  while (x){
    dig[cnt] = x % 10;
    cnt++;
    x = x / 10;
  }




}

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
      int* temp = lower_bound(prime, prime + cnt_prime, cur_sum + p);
      p_sum =(int) (temp - prime);
      
      temp = lower_bound(prime, prime + cnt_prime, cur_sqr + p * p);
      p_sqr =(int) (temp - prime);

      temp = upper_bound(prime, prime + cnt_prime, cur_sqr + p);
      p_sum_h =(int) (temp - prime);

      temp = upper_bound(prime, prime + cnt_prime, cur_sqr + p * p);
      p_sqr_h =(int) (temp - prime);


      f (j, p_sum, cnt_sum){
	f (k, p_sqr, cnt_prime){
	  res += dp[i][prime[j] - cur_sum - p][prime[k] - cur_sqr - p * p];
	}
      }
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
    x  }
    }
  }

  int* temp = upper_bound(prime, prime + cnt_prime, 162);
  cnt_sum =(int) (temp - prime);
  //cout << cnt_sum << " " << prime[cnt_sum - 1] << endl;

  

  fr (i, a){
    fr (j, b){
      fr (k, c){
	dp[i][j][k] = 0;
      }
    }
  }

  dp[0][0][0] = 1;
  int indi = 0;
  f (m, 1, 20){
    f (i, 0, 10){
      for (int j = b - 1 - i; j >= 0; j--){
	for (int k = c - 1 - i * i; k >= 0; k--){
	  dp[m][j + i][k + i * i] += dp[m - 1][j][k];
	}
      }
    }
  }

  
  f (i, 8, 9){
    cout << "----" << i << endl;
    fr (j, 18){
      fr (k, 40){
	cout << dp[i][j][k] << " ";
      }
      cout << endl;
    }
  }
  
  //cout << "start\n";
  int t;
  s(t);
  ll x, y;
  while (t--){
    sll(x); sll(y);
    cout << y << " " << luck(y) << endl;
    cout << x << " " << luck(x - 1) << endl;
    printf("%lld\n", luck(y) - luck(x - 1));
  }


  return 0;
}
