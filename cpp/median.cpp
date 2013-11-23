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
#define sc(x) scanf("%c ",&c)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)



typedef long long ll;

multiset<ll> m1;
multiset<ll> m2;
int n, c1 = 0, c2 = 0,cnt = 0;


void print(){
  multiset<ll>::iterator it;
  if (cnt%2){
    it = m2.begin();
    printf("%lld\n",*it);
    
  } else {
    it = m2.begin();
    float res = (float)(*it);
    it = m1.end();it--;
    res += (float)(*it);
    res /= 2;
    cout<<res<<endl;

  }
}

void add(ll x){
  multiset<ll>::iterator it;
  multiset<ll>::iterator jt;

  if (cnt == 0){
    m2.insert(x);
    cnt++;
    c2++;
    printf("%lld\n",x);
    return;
  }

  jt = m2.begin();
  if (cnt == 1){
    if (x <= *jt){
      m1.insert(x);cnt++;c1++;

    } else {
      m1.insert(*jt);m2.erase(jt);
      m2.insert(x);cnt++;c1++;
    }
    print();
    return;
  }

  it = m1.end(); it--;

  if (cnt%2){
    if (x <= *it){
      m1.insert(x);
      c1++;
    } else {
      m2.insert(x);
      c1++;
      jt = m2.begin();
      m1.insert(*jt);
      m2.erase(jt);
    }
  } else {
    if (x >= *jt){
      c2++;
      m2.insert(x);
    } else {
      c2++;
      m1.insert(x);
      it = m1.end(); it--;
      m2.insert(*it);
      m1.erase(it);
    }
  }

  cnt++;
  print();
}

void remove(ll x){
  multiset<ll>::iterator it;
  multiset<ll>::iterator jt;
  if(cnt == 0){
    printf("Wrong!\n");
    return;
  }

  if (cnt == 1){
    it = m2.find(x);
    if (it != m2.end()){
      m2.erase(x);
      c2--; cnt--;
    }
    printf("Wrong!\n");
    return;
  } else {
    if (cnt%2){
      it = m2.find(x);
      jt = m1.find(x);
      if (it != m2.end()){
	c2--;
	m2.erase(it);
	cnt--;
	print();
      } else if (jt != m1.end()) {
	c2--;
	m1.erase(jt);
	it = m2.begin();
	m1.insert(*it);
	m2.erase(it);
	cnt--;
	print();
      } else {
	printf("Wrong!\n");
      }

    } else {
      it = m2.find(x);
      jt = m1.find(x);

      if (jt != m1.end()){
	c1--;
	m1.erase(jt);
	cnt--;
	print();
      } else if (it != m2.end()) {
	c1--;
	m2.erase(it);
	jt = m1.end(); jt--;
	m2.insert(*jt);
	m1.erase(jt);
	cnt--;
	print();
      } else {
	printf("Wrong!\n");
      }

    }
  }
}

int main(){

  s(n); ll x; char c;
  while (n--){
    cin>>c;
    sll(x);
    if (c == 'a'){      
      add(x);
    } else {
      remove(x);
    }
  }

}


