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
#include <set>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<int, int> pi;
#define size 100000

queue<pi> q;
ll a[size];
int n, tempi;
ll d, templ, resl;
set<pi> s;
pi res[size];
int cnt = 0;

bool comp(pi x, pi y){
  if (x.first < y.first){
    return true;
  } else if (x.first == y.first && x.second < y.second){
    return true;
  } else {
    return false;
  }
}

//int x = {1, -1, 1, -1};
//int y = {-1, 1, 1, -1};

void solve(){
  fr (i, n){
    if (i) {
      if (fabs(a[i] - a[i - 1]) <= d){
	q.push(pi(i - 1, i));
	s.insert(pi(i - 1, i));
	res[cnt] = pi(i - 1, i);
	cnt++;
      }
    }
    q.push(pi(i, i));
    s.insert(pi(i, i));
  }
  set<pi>::iterator it;

  while (!q.empty()){
    pi top = q.front();
    q.pop();
    //cout << "s:" << top.first << " " << top.second << endl;
    if (top.first + 1 < n){
      if (top.second + 1 < n){
	it = s.find(pi(top.first + 1, top.second + 1));
	//cout << "da:" << fabs(a[top.first + 1] - a[top.second + 1]) << " " << (bool)(it == s.end()) << endl;
 	if (fabs(a[top.first + 1] - a[top.second + 1]) <= d && it == s.end()){
	  q.push(pi(top.first + 1, top.second + 1));
	  res[cnt] = pi(top.first + 1, top.second + 1);
	  s.insert(pi(top.first + 1, top.second + 1));
	  cnt++;
	}
      }
      if (top.second && top.first < top.second - 2){
	it = s.find(pi(top.first + 1, top.second - 1));
	//cout << "db:" << fabs(a[top.first + 1] - a[top.second - 1]) << " " << (bool)(it == s.end()) << endl;
	if (fabs(a[top.first + 1] - a[top.second - 1]) <= d && it == s.end()){
	  q.push(pi(top.first + 1, top.second - 1));
	  res[cnt] = pi(top.first + 1, top.second - 1);
	  s.insert(pi(top.first + 1, top.second - 1));
	  cnt++;
	}
      }
    }
    if (top.first){
      if (top.second + 1 < n ){
	it = s.find(pi(top.first - 1, top.second + 1));
	//cout << "dc:" << fabs(a[top.first - 1] - a[top.second + 1]) << " " << (bool)(it == s.end()) << endl;	
	if (fabs(a[top.first - 1] - a[top.second + 1]) <= d && it == s.end()){
	  q.push(pi(top.first - 1, top.second + 1));
	  res[cnt] = pi(top.first - 1, top.second + 1);
	  s.insert(pi(top.first - 1, top.second + 1));
	  cnt++;
	}
      }
      if (top.second){
	it = s.find(pi(top.first - 1, top.second - 1));
	//cout << "dd:" << fabs(a[top.first - 1] - a[top.second - 1]) << " " << (bool)(it == s.end()) << endl;
	if (fabs(a[top.first - 1] - a[top.second - 1]) <= d && it == s.end()){
	  q.push(pi(top.first - 1, top.second - 1));
	  res[cnt] = pi(top.first - 1, top.second - 1);
	  s.insert(pi(top.first - 1, top.second - 1));
	  cnt++;
	}
      }
    }
  }
}

int main(){
  s(n); sll(d);
  fr (i, n){
    sll(a[i]);
  }
  solve();
  sort(res, res + cnt, comp);
  fr (i, cnt){
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  }
  return 0;
}
