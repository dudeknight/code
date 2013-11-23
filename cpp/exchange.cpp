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

typedef long long ll;

int main(){
  int k;
  int perm[110];
  s(k);
  fr (i, k){
    s(perm[i]);
  }
  int ed[110][110];
  int b_ed[110][110];
  string st;
  fr (i, k){
    cin >> st;
    fr (j, k){
      if (st[j] == 'Y'){
	ed[i][j] = 1; 
      } else {
	ed[i][j] = 0;
      }
    }
  }

  // floyd Warshall 

  fr (i, k){
    fr (j, k){
      b_ed[i][j] = ed[i][j];
    }
  }

  fr (p, k){
    fr (i, k){
      fr (j, k){
	if (b_ed[i][p] && b_ed[p][k]){
	  b_ed[i][j] = 1;
	}
      }      
    }
  }
  
  int tperm[110];
  fr (i, k){
    tperm[i] = perm[i];
  }

  fr (i, k){
    f (j, i + 1, k){
      if (tperm[i] > tperm[j] && b_ed[i][j]){
	swap(tperm[i], tperm[j]);
      }
    }       
  }

  fr (i, k){
    if (i){
      printf(" ");
    } 
    printf("%d", tperm[i]);
  }
  printf("\n");

  return 0;
}
