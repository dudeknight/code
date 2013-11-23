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

#define sz 1000001




struct bk{
  int x;
  int y;
};

bk a[1000000];
bk b[1000000];
bool comp(bk x,bk y){
  if(x.x<y.x) return true;
  else if(x.x==y.y){
    if(x.y>y.y)
      return true;
    else return false;
  }

  return false;
}

int tmp[1000000];
int mp[1000000];
int main(){
  
  int n,m,cnt;
  // map<bk,int> mp;
  s(n);
  
  fr(i,n){
    s(a[i].x);s(a[i].y);
  }
  sort(a,a+n,comp);
  b[0]=a[0];
  mp[0]=1;
  m=1;
  f(i,1,n){
    if(a[i-1].x==a[i].x && a[i-1].y==a[i].y){
      mp[m-1]++;
    }
    else{
      mp[m]=1;
      b[m]=a[i];
      m++;
    }
  }
  


  
  
  fr(i,m){
    tmp[i]=b[i].y;
    // cout<<tmp[i]<<" ";
  }
  //cout<<endl;
  

  multiset<int> f1 (tmp,tmp+m);
  multiset<int>::iterator it;
  
 

  int res=0;
  fr(i,m){
    it=f1.lower_bound(b[i].y);
    
    f1.erase(it);
    /*
    for(it=f1.begin();it!=f1.end();it++){
      cout<<*it<<" ";
    }
    cout<<endl;
    */
    it=f1.upper_bound(b[i].y);
    if(it==f1.end())
      res+=mp[i];
  }
  printf("%d\n",res);

  return 0;
}

