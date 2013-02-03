/*
ID: dvdeepa1
PROG: packrec
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi > vvi;

// #define fi cin
// #define fo cout



int cal_c(vvi& x, vi& y){
  int mini = 0;

  fr (i, x.size()){
    int res = 0;
    fr (j, y.size()){
      res += (x[i][j] * y[j]);
    }
    mini = max(res, mini);
  }
  return mini;
}


int main(){

  fstream fi("packrec.in",fstream::in);
 
  vvi x[5];
  vvi y[5];

  x[0].resize(1);
  y[0].resize(4);
  fr (i, 4){
    x[0][0].push_back(1);
    y[0][i].resize(4);
  }
  
  fr (i, 4){
    fr (j, 4){
      y[0][i][j] = 0;
    }
    y[0][i][i] = 1;
  }

  x[1].resize(2);
  fr (i, 4){
    x[1][0].push_back(0);
    x[1][1].push_back(1);
  }
  x[1][0][0] = 1; x[1][1][0] = 0;

  y[1].resize(3);
  fr (i, 3){
    y[1][i].push_back(1);
    fr (j, 3){
      if (i != j){
	y[1][i].push_back(0);
      } else {
	y[1][i].push_back(1);
      }
    }
  }

  x[2].resize(2);  
  fr (i, 3){
    x[2][0].push_back(0);
    x[2][1].push_back(1);
  }
  x[2][0][0] = 1; x[2][1][0] = 0;
  x[2][0].push_back(1); x[2][1].push_back(1);

  y[2].resize(3);
  fr (i, 3){
    fr (j, 4){
      y[2][i].push_back(0);
    }
  }
  y[2][2][3] = 1; y[2][0][0] = 1; 
  y[2][0][1] = 1; y[2][1][0] = 1; y[2][1][2] = 1;

  x[3].resize(2);
  fr (i, 2){
    x[3][i].push_back(1);
    fr (j, 2){
      x[3][i].push_back(0);
    }
    x[3][i].push_back(1);
  }
  x[3][0][1] = 1; x[3][1][2] = 1;

  y[3].resize(3);
  fr (i, 3){
    fr (j, 4){
      y[3][i].push_back(0);
    }
  }
  y[3][0][0] = 1; y[3][2][3] = 1; y[3][1][1] = 1; y[3][1][2] = 1;


  x[4].resize(3);
  fr (i, 3){
    fr (j, 4){
      x[4][i].push_back(0);
    }    
  }
  x[4][0][0] = 1; x[4][0][3] = 1;
  x[4][1][1] = 1; x[4][1][2] = 1;
  x[4][2][1] = 1; x[4][2][3] = 1;

  y[4].resize(3);
  fr (i, 3){
    fr (j, 4){
      y[4][i].push_back(0);
    }
  }
  y[4][0][0] = 1; y[4][0][1] = 1;
  y[4][1][2] = 1; y[4][1][3] = 1;
  y[4][2][0] = 1; y[4][2][2] = 1;

  /*
  fr (i, 5){
    cout <<"i" << i << " " << x[i].size() << endl;
    fr (j, x[i].size()){
      fr (k, x[i][j].size()){
	cout << x[i][j][k] << " ";
      }
      cout << endl;
    }

  }
  */
  int a[4][2];
  fr (i, 4){
    fi >> a[i][0] >> a[i][1];
  }

  vi ax;
  vi ay;  

  int res_min = 400001;
  set<pi> res;

  int bmap[] = {1, 2, 4, 8};
  int perm[] = {0, 1, 2, 3};
  do {
    fr (i, 16){
      ax.clear();
      ay.clear();
      fr (j, 4){
	int xc = (i & bmap[perm[j]]) > 0;
	int yc = (i & bmap[perm[j]]) == 0;
	ax.push_back(a[perm[j]][xc]);
	ay.push_back(a[perm[j]][yc]);
      }
      fr (j, 5){
	int xx = cal_c(x[j], ax);
	int yy = cal_c(y[j], ay);
	if (xx > yy) swap(xx, yy);
	if (xx * yy < res_min){
	  res_min = xx * yy;	   
	  res.clear(); res.insert(pi(xx, yy));
	} else if (xx * yy == res_min){
	  res.insert(pi(xx, yy));
	}
      }
    }
  } while (next_permutation(perm, perm + 4));
  
  fi.close();
  fstream fo("packrec.out",fstream::out);	
    
  set<pi>::iterator it;
  fo << res_min << endl;
  for (it = res.begin(); it != res.end(); it++){
    fo << it->first << " " << it->second << endl;
  }
  fo.close();
  
  return 0;
}



