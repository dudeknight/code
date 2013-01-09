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

ll mod = 420047;
int m; ll n; int k;
ll res = 0;

#define msize 1<<15
#define mtsize 500

ll dp[2][msize][51];
int bt_cnt = 16;

ll mat1[mtsize][mtsize];
ll mat2[mtsize][mtsize];
ll tmp[mtsize][mtsize];
ll resm[mtsize][mtsize];

int crr[2000];
int val[2000];
int tchk[2000][2000];

int dn;
// dn is the dimension of the matrix
void init(){  
  // resm should be intialized to the identity
  // mat1 should be intialized to the  matrix which has to be exponentiated  
  fr (i, dn){
    fr (j, dn){
      resm[i][j] = 0;
    }
  }

  fr (i, dn){
    resm[i][i] = 1;
  }
  
}
 
void equalize(int x){
  if (x == 0) {
    fr (i, dn){
      fr (j, dn){
	mat2[i][j] = mat1[i][j];
      }
    }
  } else if (x == 1){
    fr (i, dn){
      fr (j, dn){
	mat2[i][j] = resm[i][j];
      }
    }
  }
}
 
void multiply(int p){
  fr (i, dn){
    fr (j, dn){
      tmp[i][j] = 0;
      fr(k, dn){
	ll x = (mat1[i][k] * mat2[k][j]) % mod;
	tmp[i][j] += x;
	tmp[i][j] %= mod;
      }
    }
  }
  
  if (p == 0){
    fr (i, dn){
      fr (j, dn){
	mat1[i][j] = tmp[i][j];
      }
    }
  } else if (p == 1){
    fr (i, dn){
      fr (j, dn){
	resm[i][j] = tmp[i][j];
      }
    }
  }
}
 
void raise(ll np){
  init();
  ll cur_pow = np;
  while (cur_pow){
    if (cur_pow & 1){
      equalize(1);
      multiply(1);
    }
    equalize(0);
    multiply(0);
    cur_pow = cur_pow >> 1;
  }
}


int correct(int x){
  int prev = x & 1;
  int cnt = x & 1;
  x >>= 1;
  fr (i, bt_cnt - 1){
    if ((x & 1) && prev){
      return -1;
    } 
    prev = x & 1;
    cnt += prev;
    x >>= 1;    
  }
  return cnt;
}


bool twice_correct(int x, int y){
  fr (i, bt_cnt){
    if ((x & 1) && (y & 1)){
      return false;
    }
    x >>= 1;
    y >>= 1;
  }
  return true;
}

void case2(){
  bt_cnt = m;
  map<int, int> mp;
  int rng = 1 << m;
  fr (i, rng){
    int x = correct(i);
    if (x != -1){
      mp[i] = x;
    }    
  }

  dn = (mp.size()) * (k + 1);
  

  fr (i, dn){
    fr (j, dn){
      mat1[i][j] = 0;
    }
  } 

  map<int,int>::iterator it, jt;
  int cnt1 = 0, cnt2 = 0;
  for (it = mp.begin(); it != mp.end(); it++){
    cnt2 = 0;
    for (jt = mp.begin(); jt != mp.end(); jt++){
      if (twice_correct(it->first, jt->first)){
	f (i, it->second, k + 1){
	  mat1[cnt1 * (k + 1) + i][cnt2 * (k + 1) + i - (it->second)] = 1;
	}
      }
      cnt2++;
    }
    cnt1++;
  }
  
  // cout << "dn " << dn << endl;
  raise(n - 1);

  res = 0;  
  cnt1 = 0;
  for (it = mp.begin(); it != mp.end(); it++){
    fr (j, mp.size()){
      res += resm[j * (k + 1) + k][cnt1 * (k + 1) + it->second];
      res %= mod;
    }
    cnt1++;
  } 
}


void case1(){
  bt_cnt = m;
  int rng = 1<<m;
  int cur = 0;
  fr (i, rng){
    int x = correct(i);
    if (x != -1){
      crr[cur] = i;
      val[cur] = x;
      cur++;
    }
  }
  rng = cur;
  // cout << "chk " << rng << endl;

  fr (i, rng){
    tchk[i][0] = 1;
    fr (j, rng){
      if (twice_correct(crr[i], crr[j])){

	tchk[i][tchk[i][0]] = j;
	tchk[i][0]++;
      }
    }
  }

  cur = 0;
  fr (j, k + 1){
    fr (i, rng){
      dp[0][i][j] = 0;
      dp[1][i][j] = 0;
    }
  }

  fr (i, rng){
    dp[0][i][val[i]] = 1; 
  }

  fr (pt, n - 1){
    //  cout << pt << endl;
    fr (i, rng){
      f (j, 1, tchk[i][0]){
	int pq = tchk[i][j];
	int x = val[pq];
	f (p, x, k + 1){
	  dp[cur ^ 1][pq][p] += dp[cur][i][p - x];
	  dp[cur ^ 1][pq][p] %= mod;
	}      
      }
    }
    
    fr (i, rng){
      fr (j, k + 1){
	dp[cur][i][j] = 0;
      }
    }
    cur ^= 1;
  }

  res = 0;
  fr (i, rng){
    res += dp[0][i][k];
    res %= mod;
    res += dp[1][i][k];
    res %= mod;
  }
}



int main(){
  int t;
  si(t);
  fr (i, t){
    si(m); sll(n); si(k);
    // cout <<"i " <<  m << " " << n << " " << k << endl;
    if (n <= 50){
      case1();
    } else {
      case2();
    }
    printf("%lld\n", res);
  }
  return 0;
}
