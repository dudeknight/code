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
typedef pair<int, int> pi;
#define size 1000000

int dp_f[26];
int dp_l[26];
int dp_c[26];
bool dp_b[26];

char c[size];

char res[30];
map<char, pi> m;
vector<vector<int> > v;
int main(){

  cin >> c;
  int n = strlen(c);

  map<char, pi>::iterator it;
  map<char, pi>::iterator jt;
  v.resize(26);
  fr (i, n){
    it = m.find(c[i]);
    if (it != m.end()){
      it->second.first = min(i, it->second.first);
      it->second.second = max(i, it->second.second);
    } else {
      m[c[i]] = pi(i, i);
    }
    v[c[i] - 'a'].push_back(i);
  }
  fr (i, 26) {
    sort(v[i].begin(), v[i].end());
  }
  int count = 0;
  int val = 0, temp1, temp2;
  vector<int>::iterator vit;
  while (!m.empty()){
    jt = m.end(); jt--;
    while (jt != m.begin()){
      for (it = m.begin(); it != m.end(); it++){
	if (jt->second.first > it->second.second)
	  break;
      }
      if (it == m.end()){
	break;
      }
      jt--;
    }
    res[count] = jt->first;
    val = jt->second.first;
    m.erase(jt);
    for (it = m.begin(); it != m.end(); it++){
      vit = upper_bound(v[it->first - 'a'].begin(), v[it->first - 'a'].end(), val);
      it->second.first = *vit;
    }
    count++;
  }
  cout << res << endl;
  return 0;
}
