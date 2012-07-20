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
#define sl(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",x);

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef int ll;

#define sz 1028

ll size;

ll bit_tree[sz+1][sz+1];
ll init_freq[sz+1][sz+1];
ll init_cumm_freq[sz+1][sz+1];


void build(){
  //cout<<"in bld"<<endl;
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
  //cout<<"in cum \n";
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
  //cout<<"in updt \n";
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
  int t;s(t);
  char key[10];
  key[3]='\0';
  while(t--){

    sll(size);
    ss(key);
    
    fr(i,size+2){
      fr(j,size+2){
	bit_tree[i][j]=0;
	init_freq[i][j]=0;
      }
    }
    while(key[0]!='E'){
      if(key[1]=='U'){
	ll a,b,c,d;
	sll(c);sll(d);sll(a);sll(b);
	long long res=get_cum(a+1,b+1)-get_cum(c,b+1)-get_cum(a+1,d)+get_cum(c,d);
	printf("%lld\n",res);
      }
      else{
	ll a,b,c;
	sll(a);sll(b);sll(c);
	update(a+1,b+1,c);
      }

      ss(key);
    }

  }

  return 0;
}

