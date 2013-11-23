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
typedef vector<int> vi;

vector<vi> v;


int main(){
  int w,h,n,q;
  cin>>w>>h>>n>>q;
  v.resize(h+1);
  v[0].push_back(0);
  v[h].push_back(w);
  
  fr(i,n){
    int x,y;
    cin>>x>>y;
    v[y].push_back(x);
    
  }

  

  while(q--){
    int x,y;
    cin>>x>>y;
    int i=y;;
    while
    

  }
  


  return 0;

}
