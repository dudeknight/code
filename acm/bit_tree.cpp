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


ll bit_tree[size+1];
ll init_freq[size+1];
ll init_cumm_freq[size+1];


void build(){
  bit_tree[0]=0;
  f(i,1,size+1){
    ll last_bit = (i&-i);
    bit_tree[i]=0;
    f(j,size-last_bit+1,i+1){
      bit_tree[i]+=init_freq[j];
    }
  }


}

ll get_cum(ll i){
  ll res=0;
  while(i>0){
    res+=bit_tree[i];
    i-=(i&-i);
  }
  return res;
}

ll update(ll i,ll v){
  ll old_v=init_freq[i];
  init_freq[i]=v;
  while(i<=size){
    bit_tree[i]+=v-old_v;
    i+=(i&-i);
  }

}




int main(){


  return 0;
}

