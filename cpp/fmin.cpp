// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

int size = 100005;

int main(){
  int t, inc = 1;
  si(t);
  ll arr[size];
  multiset<ll> st;
  multiset<ll>::iterator it, jt, kt;
  int k; ll n;
  ll a, b, c, r;
  while (t--){
    sll(n); si(k);
    sll(a); sll(b); sll(c); sll(r);
    a %= r; b %= r; c %= r; st.clear();
    arr[0] = a; st.insert(a); cout << a << " ";
    f (i, 1, k){
      arr[i] = (arr[i - 1] * b + c) % r;
      cout << arr[i] << " ";
      st.insert(arr[i]);
    }
     cout << endl;
    int cur = 0; it = st.begin(); jt = st.end(); jt--; int cur_cal = k;
    while (!((*it) == 0 && (*jt) == (k - 1)) || true){
      ll prev = arr[cur];
      it = st.begin();
      if ((*it) > 0){
	arr[cur] = 0; st.insert(0);
      } else {
	jt = st.begin(); jt++;
	while (jt != st.end()){
	  if ((*it) + 1 < (*jt)){
	    st.insert((*it) + 1); arr[cur] = (*it) + 1;
	    break;
	  }
	  it++; jt++;
	}
	if (jt == st.end()){
	  arr[cur] = (*it) + 1; st.insert(arr[cur]);
	}
      }
      it = st.find(prev); st.erase(it);
      cout << arr[cur] << " ";
      cur++; cur %= k;
      if (cur_cal == n - 1){
	break;
      }
      cur_cal++;
      it = st.begin(); jt = st.end(); jt--;
      if (cur_cal % k == 0){
	cout << endl;
      }
      
    }
    
    cout << endl;    
    cout << (*it) << " "<< (*jt) << " " << st.size() << endl;    
    for (kt = st.begin(); kt != st.end(); kt++){
      cout << (*kt) << " ";
    }
    cout << endl;
    
    arr[k] = k;
    int x = ((n - 1) - (cur_cal) + cur - 1 + k + 1) % (k + 1);
    // cout << "x " << x << " " << cur << endl;
    ll res = arr[x];
    printf("Case #%d: %lld\n", inc, res); inc++;    
  }

}
