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
    b %= r; c %= r; st.clear();
    arr[0] = a; st.insert(a); // cout << a << " ";
    f (i, 1, k){
      arr[i] = (arr[i - 1] * b + c) % r;
      // cout << arr[i] << " ";
      st.insert(arr[i]);
    }
    // cout << "d " << endl;
    // cout << endl;
    int cur = 0; it = st.begin(); jt = st.end(); jt--; int cur_cal = k;
    int strt = 0; kt = st.begin(); bool flg = false; ll flg_val;
    while (!((*it) == 0 && (*jt) == (k - 1))){
      ll prev = arr[cur];
      
      if (flg) {
	arr[cur] = flg_val; flg = false; st.insert(flg_val);
      } else if (strt < (*kt)){
	arr[cur] = strt; st.insert(strt); strt++;
      } else {
	it = kt; it++;
	while ((*it) - (*kt) <= 1 && it != st.end()){
	  it++; kt++;
	}
	strt = (*kt) + 1;	
	arr[cur] = strt; st.insert(strt); strt++; kt++;
      }
      
      it = st.find(prev);
      if (it != st.end()){
	jt = it; jt++;
	if ((*it) != (*jt) && (*it) < strt){
	  flg = true; flg_val = (*it);
	}
	if (it == kt){
	  kt++;
	}
      }
      st.erase(it);
      // cout << arr[cur] << " ";
      cur++; cur %= k;
      if (cur_cal == n - 1){
	break;
      }
      cur_cal++;
      it = st.begin(); jt = st.end(); jt--;
      /*
      if (cur_cal % k == 0){
	cout << endl;
      }
      */
      // cout << cur_cal << endl;
    }
    /*
    cout << "lie " << cur << endl;
    
    cout << endl;    
    cout << (*it) << " "<< (*jt) << " " << st.size() << endl;    
    for (kt = st.begin(); kt != st.end(); kt++){
      cout << (*kt) << " ";
    }
    cout << endl;
    */
    if (cur_cal != n - 1) {
      for (int i = k; i > cur; i--){
	arr[i] = arr[i - 1];
      }
      arr[cur] = k; cur++;
    }
    int x = ((n - 1) - (cur_cal) + cur - 1 + k + 1) % (k + 1);
    // cout << "x " << x << " " << cur << endl;
    ll res = arr[x];
    printf("Case #%d: %lld\n", inc, res); inc++;    
  }

}
