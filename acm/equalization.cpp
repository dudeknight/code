// written by lonerdude(dvdreddy)
// all rights reserved
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

bool p_seive[31];

int main(){
  int temp;
  int a[100][100];
  fr (i, 31){
    p_seive[i] = true;
  }
  p_seive[1] = false; p_seive[0] = false;
  f (i, 2, 31){
    for (int j = i * i; j < 31; j += i){
      p_seive[j] = false;
    }
  }
  int t;
  s(t);
  
  while (t--){
    int n;
    s(n);
    fr (i, n){
      s(temp);
    }
    int x = n;
    int tot_op = 0;
    f (i, 2, n + 1){
      if (x == 1){
	break;
      } else if (x % i == 0 && p_seive[i]){
	while (x % i == 0){
	  int y = n / x;
	  fr (j, x / i){
	    fr (k, y){
	      fr (p, i){
		a[tot_op][p + 1] = j * y * i + y * p + k + 1;
	      }
	      a[tot_op][0] = i;
	      tot_op++;	      	    
	    }
	  }
	  x /= i;
	}
      }
    }
    
    if (tot_op == 0){
      printf("0\n");
    } else {
      printf("%d\n", tot_op);
      fr (i, tot_op){
	fr (j, a[i][0] + 1){
	  if (j){
	    printf (" ");
	  }
	  printf("%d", a[i][j]);	  
	}
	printf("\n");
      }
    }

  }
  return 0;
}
