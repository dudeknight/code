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

struct book{
  int val;
  char bname[20];
  int top_count;
};

stack<book> st;

int main(){
  int t;
  s(t);
  int x;
  char sname[20];
  while (t--){
    s(x);
    if (st.empty()){
	book b;
	ss(b.bname);
	b.val = x;
	b.top_count = 0;
	st.push(b);      
    } else if (x != -1){
      book top = st.top();
      if (top.val < x){
	st.top().top_count++;
	ss(sname);
      } else if (x == 0){ 
	ss(sname);
      } else {
	book b;
	ss(b.bname);
	b.val = x;
	b.top_count = 0;
	st.push(b);
      }
    } else {
      book top = st.top();
      printf("%d %s", top.top_count, top.bname);
      st.pop();
    }
  }
  
  return 0;
}
