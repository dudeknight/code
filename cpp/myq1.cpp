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

char r1[]={'W','A','A','M','W'};
char d1[]={'L','L','R','R','R'};
char r0[]={'W','M','A','A','W'};
char d0[]={'R','R','R','L','L'};


int main(){
  int t;s(t);
  while(t--){
    ll n;sll(n);
    if(n==1){
      printf("poor conductor\n");
      continue;
    }
    ll rc=(n+3)/5;
    ll lf=(n+3)%5;
    char c[4];
    //    c[2]=' ';c[3]='\0';
    if(rc%2==1){
      c[1]=d1[lf];
      c[0]=r1[lf];
    }
    else{
      c[1]=d0[lf];
      c[0]=r0[lf];
    }
    //cout<<rc<<" "<<c[0]<<" "<<c[2]<<endl;
    printf("%d ",rc);printf("%c ",c[0]);printf("%c\n",c[1]);
    
  }



}
