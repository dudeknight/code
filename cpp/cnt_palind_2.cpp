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

#define f(i,a,b) for(int i = a; i < b; i++)
#define fr(i,n)  f(i,0,n)

#define rf(i,a,b) for(int i = a; i >= b; i--)
#define rfr(i,n)  rf(i, n - 1, 0)
typedef long long ll;


char st[100][100010];



int main(){
  
  int n, m;
  s(n); s(m);
  fr (i, n){ 
    ss(st[i]);
  }
 
  int res = 0;
  int px , py;
  int x = 0;
  bool strk = true;
  bool flg;


  fr (i, n){
    fr (j, n){
      if (i == j){
	continue;
      }
      fr (p, m){
	if (st[i][p] == st[j][m -  1 - p]){
	  int y = m - 1;
	  int fb = m - 2;
	  int maxi = 1;
	  while (y > p){
	    if (st[i][p + 1] == st[i][y]){
	      bool flg = true;
	      px = p + 2;
	      py = y - 1;
	      bool flg2 = true;
	      while (px < py){
		if (st[i][py] != st[i][p + 1] && flg2){
		  fb--;
		  g
		}
		if (st[i][px] != st[i][py]){
		  flg = false;
		  break;	      
		}
		px++; py--;
	      }
	      if (flg){
		maxi = y - p + 1;
		break;
	      }
	    } else {
	      y = fb; fb--;
	    }	    
	  }
	  res = max(res, 2 * p + 2 + maxi);

	  y = 0;
	  fb = 1;
	  int maxi1 = 1;
	  int pjy = m - 2 - p;
	  while (y < pjy){
	    if (st[j][pjy] == st[j][y]){
	      bool flg = true;
	      px = y + 1;
	      py = pjy - 1;
	      while (px < py){
		if (st[j][px] != st[j][pjy]){
		  fb++;
		}
		if (st[j][px] != st[j][py]){
		  flg = false;
		  break;
		}
		px++; py--;
	      }
	      if (flg){
		maxi1 = pjy - y + 1;
		break;
	      }
	    } else {
	      y = fb; fb++;
	    }	    
	  }
	  res = max(res, 2 * p + 2 + maxi1);

	} else {
	  break;
	}
      }    
    }	
  }     

  if (res >= m){
    cout << res << endl;
    return 0;
  }

  cout << res << endl;
  return 0;

}
