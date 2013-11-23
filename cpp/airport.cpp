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
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;


int main(){
  int n, m;
  int a[1000];
  int sum = 0;
  s(n); s(m);
  fr (i, m){
    s(a[i]);
    sum += a[i];
  }
  
  int min = 0;
  int temp;
  priority_queue<int> q;
  fr (i, m){
    q.push(sum - a[i]);
  }

  fr (i, n){
    min += sum - q.top();
    temp = q.top();
    q.pop();
    if (temp < sum - 1){
      temp++;    
      q.push(temp);
    }
  }

  int max = 0;
  while (!q.empty()){
    q.pop();
  }

  fr (i, m){
    q.push(a[i]);
  }

  fr (i, n){
    max += q.top();
    temp = q.top();
    q.pop();
    temp--;
    q.push(temp);
  }
  
  cout << max << " " << min << endl;
}

