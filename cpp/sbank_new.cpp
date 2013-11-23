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
typedef pair<ll, ll> pl;

struct classcomp {
  bool operator() (const pl& lhs, const pl& rhs) const {
    if (lhs.first < rhs.first){
      return true;
    } else if (lhs.first == rhs.first && lhs.second < rhs.second){
      return true;
    } else {
      return false;
    }
  }
};

map<pl, int, classcomp> a;
ll a1;int a2, a3, a4;
void print(pl x){
  printf("%08lld ",x.first);
  a1 = x.second;
  a4 = a1%10000; a1 /= 10000;
  a3 = a1%10000; a1 /= 10000;
  a2 = a1%10000; a1 /= 10000;
  printf("%04lld %04d %04d %04d ", a1, a2, a3, a4); 
}

int main(){
  map<pl, int>::iterator it;
  int t, n, temp_int, temp_int2;
  ll temp1, temp2, temp3;
  pl tempx = pl(0, 0);
  while (t){
    fr (i, 100){
      a.clear();
    }
    s(n);
    fr (i, n){
      s(temp_int);
      sll(temp1);
      sll(temp2);
      sll(temp3); temp2 = temp2 * 10000 + temp3;
      sll(temp3); temp2 = temp2 * 10000 + temp3;
      sll(temp3); temp2 = temp2 * 10000 + temp3;
      tempx.first = temp1;
      tempx.second = temp2;
      it = a.find(tempx);
      if (it != a.end()){
	it->second++;
      } else {
	a.insert(pair<pl, int>(pl(temp1, temp2), 1));
      }
    }

    fr (i, 1){
      for(it = a.begin(); it != a.end(); it++){
	printf("%02d ",i);
	print(it->first);
	printf("%d\n", it->second);
      }
    }
    t--;
    if (t){
      printf("\n");
    }
  }
  return 0;
}



