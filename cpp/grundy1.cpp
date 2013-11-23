#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

map <int, int> mp;
int g[40] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

int grundy(int mask){
  if(mp.find(mask) != mp.end()) return mp[mask];
    
  set <int> s;
  int i,j;
    
  REP(i,30) if(mask&(1<<i)){
    int mask2 = mask;
    for(j=i;j<30;j+=i) if(mask&(1<<j)) mask2 ^= (1<<j);
    s.insert(grundy(mask2));
  }
    
  for(i=0;;i++) if(s.find(i) == s.end()) break;
  return mp[mask] = i;
}

bool used[100000];
int freq[40];

int main(void){
  int i,j;
    
  int mask = 0;
  cout << "started \n";
  for(i=1;i<=29;i++){
    mask |= (1<<i);
    g[i] = grundy(mask);
    cout << g[i] << ", ";
  }
    
  cout << "dude \n";
  return 0;

  int N;
  cin >> N;
    
  freq[1] = N;
  for(int p=2;p*p<=N;p++) if(!used[p]){
      ll q = 1;
      int cnt = 0;
      while(1){
	q *= p;
	if(q > N) break;
	cnt++;
	if(q < 100000) used[(int)q] = true;
      }
      freq[1] -= cnt;
      freq[cnt]++;
    }
    
  int ans = 0;
  for(i=1;i<=29;i++) if(freq[i] % 2 == 1) ans ^= g[i];
  cout << ((ans == 0) ? "Petya" : "Vasya") << endl;
    
  return 0;
}
