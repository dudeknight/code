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

typedef int ll;

#define sz 100000

int size[2];
int t, r, cur_trans;

ll bit_tree[2][sz + 1];
ll init_freq[2][sz + 1];
ll init_cumm_freq[2][sz + 1];
int trans[sz + 1];

void build(int id){
  bit_tree[id][0]=0;
  f(i, 1, size[id] + 1){
    int last_bit = (i & -i);
    bit_tree[id][i]=0;
    f(j, size[id] - last_bit + 1, i + 1){
      bit_tree[id][i] += init_freq[id][j];
    }
  }
}

ll get_cum(int i, int id){
  ll res=0;
  while(i>0){
    res+=bit_tree[id][i];
    i-=(i&-i);
  }
  return res;
}

ll update(int i,ll v, int id){
  ll old_v=init_freq[id][i];
  init_freq[id][i]=v;
  while(i <= size[id]){
    bit_tree[id][i]+=v-old_v;
    i+=(i&-i);
  }
}

void init(){
  cur_trans = 1;
  fr (i, size[0] + 1){
    trans[i] = -1;
  }
  fr (k, 2){
    fr (i, size[k] + 1){
      init_freq[k][i] = 0;
    }
  }
  build(0); build(1);
}

int main(){
  s(t);
  int id;
  while (t--){
    s(size[0]);
    s(r); size[1] = r;
    init();
    while (r--){
      if (cur_trans > 1){
	printf(" ");
      }
      s(id);
      if (trans[id] != -1){
	//cout << "r:" << cur_trans << " " << trans[id] << " " << get_cum(cur_trans, 1) << " " << get_cum(trans[id], 1) << endl;
	printf("%d",get_cum(cur_trans, 1) - get_cum(trans[id], 1));
	update(trans[id], 0, 1);
	trans[id] = cur_trans;
      } else {
	printf("%d",id - 1 - get_cum(id, 0) + get_cum(size[0], 0));
	update(id, 1, 0);
	trans[id] = cur_trans;
      }
      update(cur_trans, 1, 1);
      cur_trans++;
    }
    printf("\n");
  }
  return 0;
}
