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
int a[100][100];

int par[100];
queue<int> pre;
queue<int> post;
bool disc[100];
bool edge_par[100][100];
int child[100];
int vert[100];

int n,k;
int temp1, temp2, temp3;
int res = 0;

void bfs_pre(int start){
  pre.push(start);
  par[start] = -1;
  fr (i, n){
    disc[i] = false;
    child[i] = 0;
  }
  while(!pre.empty()){
    int cur = pre.front();
    pre.pop();
    temp2 = 0;
    fr (i, n){
      if (a[cur][i] && par[cur] != i){
	par[i] = cur;
	pre.push(i);
	temp2++;
      }
    }
    child[cur] = temp2;
    if (temp2 == 0){
      post.push(cur);
      disc[cur] = true;
    }
  }
}

void bfs_post(){
  fr (i, n){
    vert[i] = 0;
    fr (j, n){
      edge_par[i][j] = false;
    }
  }
  while(!post.empty()){
    int cur = post.front();
    post.pop();
    if (child[cur] != 0){
      post.push(cur);
      continue;
    }
    if (par[cur] == -1)
      break;
    vert[cur]++;
    if (vert[cur] % 2 == 0 && n % 2 == 0){
      edge_par[cur][par[cur]] = true;
    }
    vert[par[cur]] += vert[cur];
    child[par[cur]]--;
    if (!disc[par[cur]]){
      post.push(par[cur]);
      disc[par[cur]] = true;
    }
  }
}

void count_edge(){
  res = 0;
  fr (i, n){
    fr (j, n){
      if (edge_par[i][j]){
	res++;
      }
    }
  }
}


int main(){
  s(n); s(k);
  fr (i, n){
    fr (j, n){
      a[i][j] = 0;
    }
  }
  fr (i, k){
    s(temp1); s(temp2);
    temp1--; temp2--;
    a[temp1][temp2] = 1;
    a[temp2][temp1] = 1;
  }
  bfs_pre(0);
  bfs_post();
  count_edge();
  cout << res << endl;
  

}

