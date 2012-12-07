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
  int t;
  s(t);
  string s1, s2;
  int a[26];
  int b[26];
  while (t--){
    cin >> s1 >> s2;
    fr (i, 26){
      a[i] = 0;
      b[i] = 0;
    }

    fr (i, s1.size()){
      a[s1[i] - 'a']++;
      b[s1[i] - 'a'] = 1;
    }

    fr (i, s2.size()){
      a[s2[i] - 'a']--;
      if (b[s2[i] - 'a'] > 0){
	b[s2[i] - 'a'] = 2;
      } else {
	b[s2[i] - 'a'] = -1;
      }
    }


    bool b1 = true;
    bool b2 = true;

    fr (i, 26){
      if (b[i] == 2 || b[i] == 0){
	b[i] = 1;
      } else {
	b[i] = 0;
      }
      
      b2 = b2 & b[i];

      if (a[i] != 0){
	a[i] = 0;
      } else {
	a[i] = 1;
      }
      b1 = b1 & a[i];
    }
    // cout << b1 << " " << b2 << endl;
    bool x = b1 ^ b2; x = !x;
    if (x) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
