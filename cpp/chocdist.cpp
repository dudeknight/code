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

#define sz 1000
int size=1000;
int kmax=51;
ll m,n;int p,q;

ll init_freq[1001][sz+1];

ll get_cum(int k,int i){
  return init_freq[k][i];
}

/*
void build(int k){
  bit_tree[k][0]=0;
  f(i,1,k+1){
    ll last_bit = (i&-i);
    bit_tree[k][i]=0;
    f(j,i-last_bit+1,i+1){
      bit_tree[k][i]+=init_freq[k][j];
    }
  }

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
*/
ll gcd(int a,int b){
  ll res=0,temp;
  while(a!=0){
    res+=(b/a);
    temp=b%a;
    b=a;a=temp;
  }
  return res;
}




int main(){

  fr(i,size+1){
    fr(j,size+1){
      init_freq[i][j]=0;
  
    }
  }

  f(i,1,size+1){
    f(j,1,i){
      init_freq[i][j]=init_freq[i][j-1]+gcd(j,i);
    }
  }

  //return 0;
  /*
  f(i,1,6){
    f(j,1,i+1){
      cout<<bit_tree[i][j]<<" ";
    }
    cout<<endl;
  }
  f(i,1,6){
    f(j,1,i+1){
      cout<<init_freq[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  //return 0;
  int t,tmp1,tmp2,rem1,rem2,temp;s(t);
  ll res;
  while(t--){
    sll(m);sll(n);s(p);s(q);
    res=0;
    f(i,p,q+1){
      tmp2=n/i;tmp1=m/i;
      rem2=n%i;rem1=m%i;
      if(tmp1==tmp2){
	res+=tmp2*(rem2-rem1+1)+get_cum(i,rem2)-get_cum(i,rem1-1);
      }
      else{
	res+=(((tmp2-tmp1-1)*(tmp2+tmp1))/2)*i;
	res+=tmp2*(rem2+1)+tmp1*(i-rem1)+(tmp2-tmp1)*get_cum(i,i-1)+get_cum(i,rem2)-get_cum(i,rem1-1);
      }
      //cout<<res<<endl;
    }
    printf("%lld\n",res);
  }
  return 0;


}

