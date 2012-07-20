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

#define size 1000


ll bit_tree[size+1][size+1];
ll init_freq[size+1][size+1];
ll init_cumm_freq[size+1][size+1];


void build(){
  bit_tree[0][0]=0;
  f(i,1,size+1){
    f(j,1,size+1){
      ll last_bit = (i&-i);
      bit_tree[i][j]=0;
      f(k,size-last_bit+1,i+1){
	ll lst_bit= (j&-j);
	f(p,size-lst_bit+1,j+1)
	  bit_tree[i][j]+=init_freq[k][p];
      }
    }
  }

}

ll get_cum(ll ix,ll iy){
  ll res=0;
  while(ix>0){
    ll y=iy;
    while(y>0){
      res+=bit_tree[ix][y];
      y-=(y&-y);
    }
    ix-=(ix&-ix);
  }
  return res;
}

ll update(ll ix,ll iy,ll v){
  ll old_v=init_freq[ix][iy];
  init_freq[ix][iy]=v;
  while(ix<=size){
    ll y=iy;
    while(y<=size){
      bit_tree[ix][y]+=v-old_v;
      y+=(y&-y);
    }
    ix+=(ix&-ix);
  }

}




int main(){


  return 0;
}

