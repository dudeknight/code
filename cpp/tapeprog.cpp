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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

vector<char> v;
ll dig[10];

int main(){
  int q; int n;
  cin >> n >> q;
  string prog;
  cin >> prog;
  while (q--){
    fr (i, 10){
      dig[i] = 0;
    }
    v.clear(); v.resize(n);
    fr (i, n){
      v[i] = prog[i];
    }
    int l; int r;
    cin >> l >> r; 
    l--;
    int curp = l;
    int curd = 1;
    while (curp < r && curp >= l){
      char c = v[curp];
      if (c == '<'){
	curd = 0;
	curp--;	
	if (curp < l) break;
	if (v[curp] - '0' >= 0 && v[curp] - '0' <= 9){
	  continue;
	}
	v.erase(v.begin() + curp + 1);
	r--;
      } else if (c == '>'){
	curd = 1;
	if (curp >= r) break;
	if (v[curp + 1] - '0' >= 0 && v[curp + 1] - '0' <= 9){
	  curp++;
	  continue;
	}
	v.erase(v.begin() + curp);
	r--;		
      } else {
	int digi = c - '0';
	dig[digi]++;
	if (digi == 0){
	  v.erase(v.begin() + curp);
	  r--;
	  if (curd == 0){
	    curp--;
	  }	  
	} else {
	  v[curp]--;
	  if (curd == 1){
	    curp++;
	  } else {
	    curp--;
	  }
	}
      }
    }
    fr (i, 10){
      cout << dig[i] << " ";
    }
    printf("\n");
  }
  


}
