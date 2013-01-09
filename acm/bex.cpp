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
#include <stack>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

#define size 1000000

int val[size];
int top_count[size];
char bname[size][30];
int stk_cnt = -1;

int main(){
  int t;
  s(t);
  int x;
  char sname[20];
  while (t--){
    if (stk_cnt < 0){
      scanf("%d %s", &val[0], bname[0]);
      stk_cnt++;
      top_count[0] = 0;
    } else {
      s(x);      
      if (x == 0){
	ss(sname);
      } else if (x != -1){
	if (val[stk_cnt] < x){
	  top_count[stk_cnt]++;
	  ss(sname);
	} else {
	  stk_cnt++;
	  ss(bname[stk_cnt]);
	  top_count[stk_cnt] = 0;
	  val[stk_cnt] = x;
	}
      } else {
	printf("%d %s\n", top_count[stk_cnt], bname[stk_cnt]);
	stk_cnt--;
      }
    }
  }
  
  return 0;
}
