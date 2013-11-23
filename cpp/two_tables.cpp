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
#define sll(x) scanf("%l64d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int a[70][70];
int b[70][70];

int main(){
  int na, ma, nb, mb;
  cin >> na >> ma;
  string st;
  fr (i, na){
    cin >> st;
    fr (j, ma){
      a[i][j] = st[j] - '0';
    }
  }
  cin >> nb >> mb;
  
  fr (i, nb){
    cin >> st;
    fr (j, mb){      
      b[i][j] = st[j] - '0';
    }
  }

  int xres = 0, yres = 0;

  int stres = 0;
  
  fr (i, min(na, nb)){
    fr(j, min(ma, mb)){
      stres += a[i][j] * b[i][j];
    }
  }
  

  fr (i, nb + na){
    fr (j, mb + ma){
      int res = 0;
      fr (p, min(na, nb - i)){
	fr (t, min(ma, mb - j)){
	  res += a[p][t] * b[p + i][t + j];
	}
      }
      if (stres < res){
	stres = res;
	xres = i;
	yres = j;
      }
    }
  }

  fr (i, na + nb){
    fr (j, ma + mb){
      int res = 0;
      fr (p, min(nb, na - i)){
	fr (t, min(mb, ma - j)){
	  res += a[p + i][t + j] * b[p][t];
	}
      }
      if (stres < res){
	stres = res;
	xres = -i;
	yres = -j;
      }
    }
  }


  fr (i, na + nb){
    fr (j, ma + mb){
      int res = 0;
      fr (p, min(na, nb - i)){
	fr (t, min(mb, ma - j)){
	  res += a[p][t + j] * b[p + i][t];
	}
      }
      if (stres < res){
	stres = res;
	xres = i;
	yres = -j;
      }
    }
  }

  fr (i, na + nb){
    fr (j, ma + mb){
      int res = 0;
      fr (p, min(nb, na - i)){
	fr (t, min(ma, mb - j)){
	  res += a[p + i][t] * b[p][t + j];
	}
      }
      if (stres < res){
	stres = res;
	xres = -i;
	yres = j;
      }
    }
  }


  cout << xres << " " << yres << endl;

}
