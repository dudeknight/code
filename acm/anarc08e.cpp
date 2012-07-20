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


int main(){
  int a,b;
  s(a);s(b);
  while(a!=-1){
    if(a==1 ||b==1){
      printf("%d+%d=%d\n",a,b,a+b);
    }
    else{
      printf("%d+%d!=%d\n",a,b,a+b);
    }
    
    s(a);s(b);
  }
  
}
