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

struct st{
  ll p;
  char c[1002];

};

bool comp(st a,st b){
  if(a.p<b.p)
    return false;
  else
    return true;

}


char qstr[1002];

st a[1000];

int main(){
  int n,q;
  s(n);
  fr(i,n){
    ss(a[i].c);
    sll(a[i].p);
  }
  //  cout<<"fdf\n";
  sort(a,a+n,comp);
  int x;
  bool b,xb;
  s(q);
  while(q--){
    ss(qstr);
    x=strlen(qstr);
    xb=true;
    fr(i,n){
      b=true;
      fr(j,x){
	if(a[i].c[j]!=qstr[j]){
	  b=false;break;
	}
      }
      if(b){
	printf("%s\n",a[i].c);
	xb=false;
	break;
	
      }
    }
    if(xb){
      printf("NO\n");
    }
   
  }


}
