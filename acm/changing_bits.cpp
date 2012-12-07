B//the template by dvdreddy
77;10003;0c
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

#define s(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define ss(x) scanf("%s", &x)
#define sc(x) scanf("%c", &x)

#define f(i, a, b) for(int i = a; i < b; i++)
#define fr(i, n)  f(i, 0, n)

typedef long long ll;

int a[2][100000];
int c[100001];

int start[100000];
char query[100000];
priority_queue<int> pq;

int main(){
  int n, q, temp;
  char ci;
  s(n); s(q);
  ss(query);
  fr (i, n){
    a[0][n - 1 - i] = query[i] - '0';
  }
  ss(query);
  fr (i, n){
    a[1][n - 1 - i] = query[i] - '0';
  }
  int carry = 0, ind = 0, cur, plc, aplc;
  bool change, carry_flg;
  fr (i, n){
    temp = carry + a[0][i] + a[1][i];
    if (temp > 2){
      carry = 1;
      c[i] = temp % 2;
    } else {
      carry = 0;
      c[i] = temp;
    }
  }

  c[n] = carry;
  change = false;
  while (q--){
    ss(query);
    if (query[0] == 'g'){
      s(ind);
      printf("%d", c[ind]);
    } else {
      s(ind); s(temp);
      plc = query[4] - 'a';
      aplc = (plc + 1) % 2;
      if (a[plc][ind] != temp){
	if (a[plc][ind] == 1 && a[aplc][ind] == 1){
	  if (c[ind] == 0){
	    c[ind] = 1;
	    cur = ind + 1;
	    while (!((a[0][cur] ==0 && a[1][cur] == 0 ) || (a[0][cur] == 1 && a[1][cur] == 1 )) && cur < n){
	      cur++;
	    }
	    c[cur] = 0;
	    a[plc][ind] = temp;
	  } else {
	    c[ind] = 1;
	    a[plc][ind] = temp;
	  }
	} else if (a[plc][ind] == 0 && a[aplc][ind] == 1){
	  if (c[ind] == 0){
	    c[ind] = 1;
	    a[plc][ind] = temp;
	  } else {
	    c[ind] = 0;
	    cur = ind + 1;
	    while (!((a[0][cur] ==0 && a[1][cur] == 0 ) || (a[0][cur] == 1 && a[1][cur] == 1 )) && cur < n){
	      c[cur] = 0;
	      cur++;
	    }
	    c[cur] = 1;
	    a[plc][ind] = temp;
	  }
	} else if (a[plc][ind] == 1 && a[aplc][ind] == 0){
	  if (c[ind] == 0){
	    c[ind] = 1;
	    cur = ind + 1;
	    while (!((a[0][cur] ==0 && a[1][cur] == 0 ) || (a[0][cur] == 1 && a[1][cur] == 1 )) && cur < n){
	      cur++;
	    }
	    c[cur] = 0;
	    a[plc][ind] = temp;
	    
	  } else {
	    c[ind] = 0;
	    a[plc][ind] = temp;
	  }
	} else {
	  if (c[ind] == 0){
	    c[ind] = 1;
	    a[plc][ind] = temp;
	  } else {
	    c[ind] = 0;
	    cur = ind + 1;
	    while (!((a[0][cur] ==0 && a[1][cur] == 0 ) || (a[0][cur] == 1 && a[1][cur] == 1 )) && cur < n){
	      c[cur] = 0;
	      cur++;
	    }
	    c[cur] = 1;
	    a[plc][ind] = temp;
	  }
	}
      }
    }
  }
  cout << endl;
  return 0;
}


