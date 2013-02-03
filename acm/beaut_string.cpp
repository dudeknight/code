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

#define si(x) scanf("%d\n",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int t;
  si(t); int inc = 1;
  while (t--){
    char cx[510];
    cin.getline(cx, 505);
    int n = strlen(cx);
    int char_cnt[26];
    fr (i, 26){
      char_cnt[i] = 0;
    }
    fr (i, n){
      char c = cx[i];
      if (c >= 'A' && c <= 'Z'){
	char_cnt[c - 'A']++;
      } else if (c >= 'a' && c <= 'z'){
	char_cnt[c - 'a']++;
      }
    }
    int res  = 0;
    sort(char_cnt, char_cnt + 26);
    fr (i, 26){
      res += (char_cnt[25 - i] * (26 - i));
    }
    printf("Case #%d: %d\n", inc, res);
    inc++;
  }
  return 0;
}
