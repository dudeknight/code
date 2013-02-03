/*
ID: dvdeepa1
PROG: clocks
LANG: C++
*/
// written  by lonerdude (dvdreddy)
// all rights reserved
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <fstream>
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
typedef pair<ll, string> pls;


int lim = (int)(1 << 18); 
int cs[1 << 18]; int cs_cnt[1 << 18]; int cs_cx[1 << 18][9];

bool comp(string& s1, string& s2){
  if (s1.size() == s2.size()){
    return (s1 < s2);
  } else {
    return (s1.size() < s2.size());
  }
}

bool comp2 (int x, int y){
  int c1 = cs_cnt[x], c2 = cs_cnt[y];
  if (c1 == c2){
    fr (i, 9){
      if (cs_cx[x][i] != cs_cx[y][i]){
	return (cs_cx[x][i] < cs_cx[y][i]);
      }
    }    
  } else {
    return (c1 < c2);
  }
}


// #define fi cin
// #define fo cout

int main(){
  int a[9][9];
  fr (i, 9){
    fr (j, 9){
      a[i][j] = 0;
    }
  }

  string s_moves[] = {"abde", "abc", "bcef", "adg", "bdefh", "cfi", "degh", "ghi", "efhi"};
  string c_moves[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}; 

  fr (i, 9){
    fr (j, s_moves[i].size()){
      a[i][s_moves[i][j] - 'a'] = 1;
    }
  }
  
  ll moves[9]; ll clear_move = 0;
  fr (i, 9){
    clear_move <<= 3; clear_move += (ll)3;
  }
  fr (i, 9){
    moves[i] = 0;
    fr (j, 9){
      moves[i] <<= 3; moves[i] += (ll)(a[i][j]);
    }
  }

  int ms = 90000; int qcur = 1; int qfront = 0;

  ll q1[ms];
  string q2[ms];

  fstream fi("clocks.in",fstream::in);
  ll st_state = 0; ll x;

  
  fr (i, lim){
    cs[i] = i; cs_cnt[i] = 0; int xt = i;
    fr (j, 9){
      cs_cx[i][j] = xt & 3; xt >>= 2; cs_cnt[i] += cs_cx[i][j];
    }
  }
  sort(cs, cs + lim, comp2);
  // return 0;
  fr (i, 9){
    fi >> x;
    st_state <<= 3; st_state += (ll)((x / 3) % 4);
  }
  int cnt[9]; bool flg = false; string str_res = "v"; int curs = 0;
  fr (i, lim){
    int xt = cs[i];
    string temp = ""; ll tmp_st = st_state;
    fr (j, 9){
      fr (k, cs_cx[xt][j]){
	tmp_st = tmp_st + moves[j]; tmp_st &= clear_move;
	temp += c_moves[j];
      }
    }
    if (tmp_st == 0){
      str_res = temp; break;
    }      
  }
  

  fi.close();
  fstream fo("clocks.out",fstream::out);	

  fr (i, str_res.size()){
    if (i){
      fo << " ";
    }
    fo << str_res[i];
  }
  fo << endl;
  fo.close();
  
  return 0;
}



