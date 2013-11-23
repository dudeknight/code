/*
ID: dvdeepa1
PROG: ariprog
LANG: C++
*/
// written  by lonerdude (dvdreddy)
// all rights reserved
#include <vector>
#include <queue>
#include <deque>
#include <map>
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

#define fi cin

#define fo cout

typedef pair<int, int> pi;

int num[125001];
bool bl[125001];
int n, m, cnt;

pi x[10001];
int res_cnt;

void pre(){
  fr (i, 125001){
    bl[i] = false;
  }
  cnt = 0;
  fr (i, m + 1){
    f (j, i, m + 1){
      int tmp = i * i + j * j;
      if (!bl[tmp]){
	bl[tmp] = true; num[cnt] = tmp; cnt++;
      }
    }
  }
  sort(num, num + cnt);  

}


void process(){
  res_cnt = 0;
  
  fr (i, cnt - n + 1){
    int st = num[i];
    f (j, i + 1, cnt - n + 2){
      int diff = num[j] - num[i];
      if (st + (n - 1) * diff > num[cnt - 1]){
	break;
      } else {
	int xs = st; bool p = true;
	fr (k, n){
	  if (!bl[xs]) {
	    p = false; break;
	  }
	  xs += diff;
	}
	if (p){
	  x[res_cnt] = pi(diff, st); res_cnt++;
	}
      }
    }
  }

  sort(x, x + res_cnt);
}

int main(){  
  // fstream fi("ariprog.in",fstream::in);
  fi >> n >> m;
  pre();
  process();  
  
  // fi.close();
  // fstream fo("ariprog.out",fstream::out);	
  
  fr (i, res_cnt){
    fo << x[i].second << " " << x[i].first << endl;
  }
  if (res_cnt == 0){
    fo << "NONE\n";
  }
  // fo.close();  
  return 0;
}



