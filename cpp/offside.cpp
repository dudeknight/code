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


int a[100];
int d[100];

int na,nd;


int main(){
  s(na);s(nd);

  while(na!=0 &&nd!=0){
    fr(i,na)
      s(a[i]);
    fr(i,nd)
      s(d[i]);
    sort(a,a+na);
    sort(d,d+nd);

    //    int tmp=a[0];
    
    if(a[0]>=d[1])
      printf("N\n");
    else
      printf("Y\n");

    s(na);s(nd);
  }
  



}
