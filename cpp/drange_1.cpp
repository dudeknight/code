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
typedef pair<ll, ll> pl;

#define sizem 10000

struct rng{
  int x;
  int y;
  ll w;
};

pl tree[6 * sizem + 20];
bool update[6 * sizem + 20];
ll value[6 * sizem + 20];
ll a[2 * sizem + 10];
rng b[2 * sizem + 10];
int mapping[100 * sizem + 5];

int n, m;
int temp1, temp2;
int sizer = 0;
int tree_size;

void intialize(int i, int j, int k){
  tree[k].first = a[i];
  tree[k].second = a[j];
  update[k] = true;
  if (j != i){
    intialize(i, (i + j) / 2, 2 * k + 1);
    intialize((i + j) / 2 + 1, j, 2 * k + 2);
    tree_size = max(tree_size, 2 * k + 2);
  }
}

void print_tree_helper(int i, int j, int cnt, int k){
  fr (x, cnt){
    cout << " " ;
  }
  cout << tree[k].first << " " << tree[k].second << endl;
  if (i != j){
    print_tree_helper(i, (i + j) / 2, cnt + 1, 2 * k + 1);
    print_tree_helper((i + j) / 2 + 1, j, cnt + 1, 2 * k + 2);
  }
}

void print_tree(){
  cout << "-----------\n";
  print_tree_helper(0, sizer - 1, 0, 0);
  cout << "-----------\n";
}

void update_helper(int i, int j, rng r, int k){
  if (k != 0 && update[(k - 1) / 2]){
    tree[k].first += value[(k - 1) / 2];
    tree[k].second += value[(k - 1) / 2];
    update[k] = true;
    value[k] += value[(k - 1) / 2];
  }
  if (i > r.y || j < r.x)
    return;
  if (i >= r.x && j <= r.y){
    tree[k].first += r.w;
    tree[k].second += r.w;
    update[k] = true;
    value[k] += r.w;
    return;
  }
  if (j != i){
    update_helper(i, (i + j) / 2, r, 2 * k + 1);
    update_helper((i + j) / 2  + 1, j, r, 2 * k + 2);
    tree[k].first = min(tree[2 * k + 1].first, tree[2 * k + 2].first);
    tree[k].second = max(tree[2 * k + 1].second, tree[2 * k + 2].second);
  }
  update[k] = false;
  value[k] = 0;
}


void update_main(){
  fr (i, m){
    print_tree();
    update_helper(0, sizer - 1, b[i], 0);
  }
  print_tree();
}

int main(){
  int t;
  s(t);
  set<ll>::iterator it;
  while (t--){
    s(n); s(m);
    a[0] = 1;
    a[1] = n;
    fr (i, m){
      s(temp1);
      s(b[i].x);
      s(b[i].y);
      sll(b[i].w);
      if (temp1 == 2){
	b[i].w *= -1;
      }
      a[2 * i + 2] = b[i].x;
      a[2 * i + 3] = b[i].y;
    }
    set<ll> srt(a, a + 2 * m + 2);
    temp1 = 0;
    for (it = srt.begin(); it != srt.end(); it++){
      a[temp1] = *it;
      mapping[*it] = temp1;
      temp1++;
    }
    fr (i, m){
      b[i].x = mapping[b[i].x];
      b[i].y = mapping[b[i].y];
    }
    sizer = temp1;
    tree_size = 1;
    intialize(0, sizer - 1, 0);
    update_main();
    printf("%lld\n", tree[0].second - tree[0].first);
  }
  return 0;
}
