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

#define nsize 10000
#define msize 100000

typedef long long ll;
typedef pair<int,int> pi;

ll mod = 1000000000;
ll disc[nsize];
pi edges[msize];
int edges_start[nsize];
int edges_end[nsize];

bool comp(pi x, pi y){
  if (x.first < y.first){
    return true;
  } else {
    if (x.second < y.second){
      return true;
    } else {
      return false;
    }
  }
}

int main(){
  int m, n;
  s(n); s(m);
  fr (i, m){
    s(edges[i].first); edges[i].first--;
    s(edges[i].second); edges[i].second--;
  }
  
  sort(edges, m, comp);
  edges_start[0] = 0;
  int cur = 0;
  fr (i, m){
    while (cur != edges[i].first){
      edges_end[cur] = i;
      cur++;
      edges_start[cur] = i;
    }
  }
  
  return 0;
}

