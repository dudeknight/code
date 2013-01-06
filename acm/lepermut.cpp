#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

long long a[110];
long long b[110];
int n;


void mymerge(int i,int j,int k){
  int x=i;
  int y=j;
  int c=i;	
  while(x<j and y<k){
    if(a[x]<=a[y]){
      b[c]=a[x];x++;
    }
    else{
      b[c]=a[y];y++;
    }
    c++;
  }
  while(x<j){
    b[c]=a[x];x++;c++;
  }
  while(y<k){
    b[c]=a[y];y++;c++;
  }
  f(p,i,k){
    a[p]=b[p];
  }
}



long long mycount(int i,int j,int k){
  long long res=0;
  int x=i;
  int y=j;
  while(x<j && y<k){
    if(a[x]<=a[y]){
      res+=(y-j);
      x++;
    }
    else
      y++;
  }
  while(x<j){
    res+=(k-j);
    x++;
  }

  return res;
}



long long func(){
  long long res=0;
  int m=1;
  while(m<n){
    int i=0;
    while(i<n-m){
      res+=mycount(i,i+m,min(i+2*m,n));
      mymerge(i,i+m,min(i+2*m,n));
      i+=2*m;
    }
    m*=2;
  }

  return res;
}

		


int main(){
  int t;
  s(t);
  while(t--){
    s(n);
    f(i,0,n)
      sll(a[i]);
    int emp = 0;
    fr(i, n - 1){
      if (a[i] > a[i + 1]){
	emp++;
      }
    }
    int cnt = (int) func();
    if (cnt == emp){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
