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
#define mod 5000000
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

#define sz 20000
ll size;
int kmax=51;
int xk;

ll bit_tree[51][sz+1];
ll init_freq[51][sz+1];
ll a[sz+1];
ll b[sz+1];

void build(int k){
  bit_tree[k][0]=0;
  f(i,1,size+1){
    ll last_bit = (i&-i);
    bit_tree[k][i]=0;
    f(j,size-last_bit+1,i+1){
      bit_tree[k][i]+=init_freq[k][j];
    }
  }

}

ll get_cum(int k,ll i){
  ll res=0;
  if(i==0) return 0;
  while(i>0){
    res+=bit_tree[k][i];
    res%=mod;
    i-=(i&-i);
  }
  return res;
}

void update(int k,ll i,ll v){
  //  ll old_v=init_freq[i];
  if(i==0) return;
  init_freq[k][i]+=v;
  while(i<=size){
    bit_tree[k][i]+=v;
    bit_tree[k][i]%=mod;
    i+=(i&-i);
  }

}




int main(){
  sll(size);s(xk);			
  fr(i,size){
    sll(a[i]);
    b[i]=a[i];
  }
  fr(i,xk+1){
    fr(j,size+1){
      bit_tree[i][j]=0;
    }
  }
    
  sort(b,b+size);
  //cout<<"inp done\n";
  fr(i,size){
    ll* lo=lower_bound(b,b+size,a[i]);
    int v=(int)(lo-b);
    //cout<<v<<endl;
    update(0,v+1,1);
    f(j,1,xk){
      ll cumv=get_cum(j-1,v);
      update(j,v+1,cumv);
    }
  }
  /*
  fr(i,xk){
    fr(j,size+1){
      cout<<init_freq[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  printf("%lld\n",get_cum(xk-1,size+1));

  return 0;
}

