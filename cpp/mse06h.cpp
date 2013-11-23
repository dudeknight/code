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
#define sll(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)
#define sz 1002
typedef int ll;

ll a[1000010];
ll b[1000010];
ll n,m,k,size;


struct pr{
  ll x;
  ll y;
};

pr in_arr[1000020];


bool mycomp(pr a,pr b){
  if(a.x<b.x) return true;
  else if(a.x==b.x && a.y < b.y) return true;
  else return false;
}




ll bit_tree[sz+1];
ll init_freq[sz+1];
ll init_cumm_freq[sz+1];


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
  //ll old_v=0;
  //init_freq[i]=v;
  while(i<=size){
    bit_tree[i]+=v;//-old_v;
    i+=(i&-i);
  }

}





int main(){
  ll t; sll(t);
  ll cs=1;
  while(t--){
    sll(n);sll(m);sll(k);
    fr(i,k){
      sll(in_arr[i].x);
      sll(in_arr[i].y);
    }
    sort(in_arr,in_arr+k,mycomp);
    size=m;
    fr(i,size+1){
      bit_tree[i]=0;
    }
    long long res=0;
    fr(i,k){
      update(in_arr[i].y,1);
      res+=(i+1)-get_cum(in_arr[i].y);
      //cout<<a[i]<<" ";
    }
    //cout<<endl;

    printf("Test case %d: %lld\n",cs,res);
    cs++;
  }
  
  return 0;
}

