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

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int main(){
  int t;
  si(t);
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 3; i++){
      if (s[i] == '?'){
	
      }
    }
    f (i, size() - 3, s.size()){
      if (s[i] == '?'){
	s[i] = 'A';
      }
    }
    cout << s << endl;
  }

}
