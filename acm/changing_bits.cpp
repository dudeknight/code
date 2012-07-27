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

#define s(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define ss(x) scanf("%s", &x)
#define sc(x) scanf("%c", &c)

#define f(i, a, b) for(int i = a; i < b; i++)
#define fr(i, n)  f(i, 0, n)

typedef long long ll;

int a[2][100000];
int c[100001];

int start[10000];
char query[10];
priority_queue<int> pq;

int main(){
  int n, q, temp;
  s(n); s(q);
  char c;
  fr (i, n){
    sc(c);
    a[0][i] = c - '0';
  } 
  fr (i, n){
    sc(c);
    a[1][i] = c - '0';
  }
  int carry = 0, ind = 0;
  bool change, carry_flg, plc;
  fr (i, n){
    temp = carry + a[0][n - 1 - i] + a[1][n - 1 - i];
    if (temp > 2){
      carry = 1;
      c[n - 1 - i] = temp % 2;
    } else {
      carry = 0;
      c[n - 1 - i] = temp;
    }
  }
  c[0] = carry;
  change = false;
  while (q--){
    ss(query);
    if (query[0] == 'g'){
      s(ind);
      if (change){
	temp = q.top();
	q.pop();
	while (q.empty() || cur <= 0){
	  
	}
      }
      printf("%d", c[ind];
    } else {
      s(ind); s(temp);
      plc = query[4] - 'a';
      if (a[plc][ind] != temp){
	pq.push(ind);
	a[plc][ind] = temp;
	change = true;
      }
    }
  }
  return 0;
}
