#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
 
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
 
#include <stdio.h>
 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
 
using namespace std;
 
// Useful Constants
#define INF    (int)        2147483646                        //one less than the max
#define LINF   (long long)  9223372036854775806               //one less than the max
#define EPS                 1e-9                              //Arbitrary
#define PI                  3.1428571428571428571428571428571
#define E                   2.7182818284590452353602874713526
 
//Useful Macros
#define MAX(i,j)            ((i)>(j)?(i):(j))
#define MIN(i,j)            ((i)<(j)?(i):(j))
#define ABS(i)              ((i)<0?-(i):(i))
#define REP(i,a)            for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b)          for((i)=a;(i)<(b);(i)++)
#define FORE(i,a,b)         for((i)=a;(i)<=(b);(i)++)
#define EACH(it,b)          for(__typeof((b).begin())it=(b).begin();it!=(b).end();it++)
#define CLRI(ptr,n)         memset((ptr),0,(n)*sizeof(int))
#define CLRC(ptr,n)         memset((ptr),0,(n)*sizeof(char))
 
//Useful Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <string> vs;
typedef map<char,int> mci;
typedef map<int,int>  mii;
 
//Fast stdin class (my windows g++ doesn't have getchar_unlocked, so this will have to do)
class FastInput {
public:
  FastInput();
  FastInput(const char *filename);
  inline void getint(int &n);
  inline void getstr(char k[]);
  inline void getlcstr(char k[]);
  inline void getnumstr(char k[]);
  inline void getull(ull &n);
 
  // No bars on the windows -- but these aren't really public
  inline void nextchar(char &c);
  inline void getmore();
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *bufend;
  bool debug_mode;
  ifstream mystream;
};
 
char FastInput::buffer[FastInput::BUFSIZE];
 
FastInput::FastInput() { debug_mode = false; getmore(); }
 
FastInput::FastInput(const char *filename) {
  debug_mode = true;
  mystream.open(filename);
  getmore();
}
 
inline void FastInput::getmore() {
  bufpos = buffer;
#ifdef ONLINE_JUDGE
  bufend = buffer + read(0, buffer, BUFSIZE);
#else
  if (debug_mode) {
    mystream.read(buffer,BUFSIZE);
    bufend = buffer + mystream.gcount();
  } else {
    cin.read(buffer,BUFSIZE);
    bufend = buffer + cin.gcount();
  }
#endif
}
 
inline void FastInput::nextchar(char &c) {
  c = *bufpos++;
  if (bufpos==bufend) getmore();
}
 
inline void FastInput::getint(int &n) {
  n = 0;
  register char ch;
  register char lch = ' ';
  nextchar(ch);
  while (ch < '0' || ch > '9') {
    lch = ch;
    nextchar(ch);
  }
  while (ch >= '0' && ch <= '9') {
    n=(n<<3)+(n<<1)+ch-'0';
    nextchar(ch);
  }
  if (lch=='-') n = -n;
}
 
inline void FastInput::getull(unsigned long long &n) {
  n = 0;
  register char ch;
  register char lch = ' ';
  nextchar(ch);
  while (ch < '0' || ch > '9') {
    lch = ch;
    nextchar(ch);
  }
  while (ch >= '0' && ch <= '9') {
    n=(n<<3)+(n<<1)+(ch-'0');
    nextchar(ch);
  }
  //if (lch=='-') n = -n;
}
 
inline void FastInput::getlcstr (char k[]) {
  register int cnt = 0;
  register char ch;
  nextchar(ch);
  while ( ch < 'a' || ch > 'z' ) nextchar(ch);
  while (ch >= 'a' && ch <= 'z') {
    k[cnt++] = ch;
    nextchar(ch);
  }
  k[cnt] = '\0';
}
 
inline void FastInput::getstr (char k[]) {
  register int cnt = 0;
  register char ch;
  nextchar(ch);
  while (( ch < 'a' || ch > 'z' ) &&
	 ( ch < 'A' || ch > 'Z' )) nextchar(ch);
  while ((ch >= 'a' && ch <= 'z') ||
	 (ch >= 'A' && ch <= 'Z')) {
    k[cnt++] = ch;
    nextchar(ch);
  }
  k[cnt] = '\0';
}
 
inline void FastInput::getnumstr (char k[]) {
  register int cnt = 0;
  register char ch;
  nextchar(ch);
  while ( ch < '0' || ch > '9' ) nextchar(ch);
  while (ch >= '0' && ch <= '9') {
    k[cnt++] = ch;
    nextchar(ch);
  }
  k[cnt] = '\0';
}
 
class FastOutput {
public:
  FastOutput();
  ~FastOutput() { flush(); }
  inline void wrchar(char c);
  inline void flush();
  inline void putint(int n,char c);
  inline void putstr(char *k);
  inline void putll(ll n, char c);
  inline void putull(ull n, char c);
  inline void putuint(unsigned int n, char c);
 
  // No bars on the windows -- but these aren't really public
  static const int BUFSIZE = 1<<16;
  static char buffer[];
  char *bufpos;
  char *bufend;
};
 
char FastOutput::buffer[FastOutput::BUFSIZE];
 
FastOutput::FastOutput() { bufpos = buffer; bufend = bufpos + BUFSIZE; }
 
inline void FastOutput::wrchar(char c) {
  *bufpos++ = c;
  if (bufpos == bufend) { flush(); }
}
 
inline void FastOutput::flush() {
  if (bufpos == buffer) { return; }
#ifdef ONLINE_JUDGE
  write(1, buffer, bufpos-buffer);
#else
  cout.write(buffer,bufpos-buffer);
#endif
  bufpos = buffer;
}
 
inline void FastOutput::putstr(char *k) {
  while (*k != 0) { wrchar(*k++); }
}
 
inline void FastOutput::putint(int n, char c) {
  char buf[32];
  char *bufptr;
  bufptr = buf + 31;
  *bufptr-- = 0;
  if (c > 0) { *bufptr-- = c; }
  if (n == 0) { *bufptr-- = '0'; }
  else if (n < 0) { *bufptr-- = '-'; n = -n; }
  else {
    while (n > 0) { int r = n % 10; *bufptr-- = '0'+r; n /= 10; }
  }
  putstr(++bufptr);
}
 
 
inline void FastOutput::putll(ll n, char c) {
  char buf[32];
  char *bufptr;
  bufptr = buf + 31;
  *bufptr-- = 0;
  if (c > 0) { *bufptr-- = c; }
  if (n == 0) { *bufptr-- = '0'; }
  else if (n < 0) { *bufptr-- = '-'; n = -n; }
  else {
    while (n > 0) { int r = n % 10; *bufptr-- = '0'+r; n /= 10; }
  }
  putstr(++bufptr);
}
 
inline void FastOutput::putull(ull n, char c) {
  char buf[32];
  char *bufptr;
  bufptr = buf + 31;
  *bufptr-- = 0;
  if (c > 0) { *bufptr-- = c; }
  if (n == 0) { *bufptr-- = '0'; }
  else {
    while (n > 0) { int r = n % 10; *bufptr-- = '0'+r; n /= 10; }
  }
  putstr(++bufptr);
}
 
inline void FastOutput::putuint(unsigned int n, char c) {
  char buf[32];
  char *bufptr;
  bufptr = buf + 31;
  *bufptr-- = 0;
  if (c > 0) { *bufptr-- = c; }
  if (n == 0) { *bufptr-- = '0'; }
  else {
    while (n > 0) { int r = n % 10; *bufptr-- = '0'+r; n /= 10; }
  }
  putstr(++bufptr);
}

 
 
 
 
 
 
 
unsigned int  ds23[19][19][55][37];
unsigned int  ds57[19][19][19][19];
unsigned int  ds0[37];
unsigned int  combarr[19][19];
 
void calc23ds() {
  int i, j, k, l, num, denom, two, three;
  REP(i,19) {
    REP(j,19) {
      REP(k,55) {
	REP (l,37) { ds23[i][j][k][l] = 0; } } } }
  // Take care of the zero case
  REP(i,19) { ds23[0][i][0][0] = 1; }
 
  FORE(num,1,18) {
    FORE(denom,0,18) {
      if (denom == 0) {
	FORE(two,0,3*num-3) {
	  int num8s = two/3;
	  int threemax = (num-1-num8s)*2 - (two % 3);
	  FORE(three,0,threemax) {
	    unsigned int adder = ds23[num-1][denom][two][three];
	    ds23[num][denom][two][three]     += adder;
	    ds23[num][denom][two+1][three]   += adder;
	    ds23[num][denom][two+2][three]   += adder;
	    ds23[num][denom][two+3][three]   += adder;
	    ds23[num][denom][two][three+1]   += adder;
	    ds23[num][denom][two][three+2]   += adder;
	    ds23[num][denom][two+1][three+1] += adder;
	  }
	}
      }
 
      else {
	FORE(two,0,3*num) {
	  int num8s = two/3;
	  int threemax = (num-num8s)*2 - (two % 3);
	  FORE(three,0,threemax) {
	    unsigned int adder = ds23[num][denom-1][two][three];
	    ds23[num][denom][two][three]     += adder;
	    if (two >= 1)                    { ds23[num][denom][two-1][three]   += adder; }
	    if (two >= 2)                    { ds23[num][denom][two-2][three]   += adder; }
	    if (two >= 3)                    { ds23[num][denom][two-3][three]   += adder; }
	    if (three >= 1)                  { ds23[num][denom][two][three-1]   += adder; }
	    if (three >= 2)                  { ds23[num][denom][two][three-2]   += adder; }
	    if ((two >= 1) && (three >= 1))  { ds23[num][denom][two-1][three-1] += adder; }
	  }
	}
      }
    }
  }
}
 
void calc57ds() {
  int i, j, k, l, num, denom, five, seven;
  REP(i,19) {
    REP(j,19) {
      REP(k,19) {
	REP (l,19) { ds57[i][j][k][l] = 0; } } } }
  ds57[0][0][0][0] = 1;
 
  FORE(num,1,18) {
    FORE(denom,0,MIN(num+1,18)) {
      if (denom == 0) {
	FORE(five,0,num-1) {
	  seven = (num-1) - five;
	  unsigned int adder = ds57[num-1][denom][five][seven];
	  ds57[num][denom][five+1][seven] += adder;
	  ds57[num][denom][five][seven+1] += adder;
	}
      }
 
      else {
	FORE(five,0,num-(denom-1)) {
	  seven = num - (denom-1) - five;
	  unsigned int adder = ds57[num][denom-1][five][seven];
	  if (five > 0)  { ds57[num][denom][five-1][seven] += adder; }
	  if (seven > 0) { ds57[num][denom][five][seven-1] += adder; }
	  ds57[num][denom][five][seven+1] += adder;
	}
      }
    }
  }
}
 
void calc0ds() {
  int i,l;
  unsigned int power10[19];
  unsigned int power9[19];
  unsigned int p9 = 1;
  unsigned int p10 = 1;
  REP(i,37) {ds0[i] = 0; }
  REP(i,19) {
    power10[i] = p10; p10 *=  10U;
    power9[i] = p9;   p9 *=  9U;
  }
  ds0[0] = 0;
  ds0[1] = 0;
  ds0[2] = 0;
  FORE(l,3,36) {
    int denom = l/2;
    int num = denom + l % 2;
    unsigned int ways = 9;
    ways *= (power10[num-1] - power9[num-1]);
    ways *= power9[denom];
    ds0[l] = ways;
  }
}
 
void setcomb() {
  int i, j;
  unsigned int n, r;
  REP(i,19) {
    REP(j,19) {
      combarr[i][j] = 0;
    }
  }
  FORE(n,0,18) {
    FORE(r,0,n) {
      if (r == 0) { combarr[n][r] = 1; }
      else        { combarr[n][r] = combarr[n-1][r-1] * n / r; }
    }
  }
}
 
void factor(ull n, int &twos, int &threes, int &fives, int &sevens, ull &residual) {
  twos = 0; threes = 0; fives = 0; sevens = 0;
  if (n == 0) { residual = n; return; }
  if (n % 2 == 0) {
    while (n % 512 == 0) { twos+=9; n /= 512; }
    while (n % 8 == 0)   { twos+=3; n /= 8; }
    while (n % 2 == 0)   { twos+=1; n /= 2; }
  }
  if (n % 3 == 0) {
    while (n % 729 == 0) { threes+=6; n /= 729; }
    while (n % 9 == 0)   { threes+=2; n /= 9; }
    while (n % 3 == 0)   { threes+=1; n /= 3; }
  }
  if (n % 5 == 0) {
    while (n % 625 == 0) { fives+=4; n /= 625; }
    while (n % 5 == 0)   { fives+=1; n /= 5; }
  }
  if (n % 7 == 0) {
    while (n % 2401 == 0) { sevens+=4; n /= 2401; }
    while (n % 7 == 0)    { sevens+=1; n /= 7; }
  }
  residual = n; return;
}
 
 
unsigned int solve (ull n, int num, int denom) {
  if (n == 0) { return ds0[num+denom]; }
  int two, three, five, seven;
  ull residual;
  factor(n,two,three,five,seven,residual);
  if (residual > 1) { return 0; }
 
  int num8s = two/3;
  int slotsleft = (two%3) + three;
  int min23dig = num8s + slotsleft/2 + slotsleft% 2;
  unsigned int ways = 0;
  int num23, denom23, num57, denom57;
  FORE(num23,min23dig,num-five-seven) {
    num57 = num-num23;
    denom57 = num57-five-seven;
    denom23 = denom-denom57;
    if (denom23 < 0) { continue; }
    unsigned int myds23 = ds23[num23][denom23][two][three];
    unsigned int myds57 = ds57[num57][denom57][five][seven];
    unsigned int comb1 = combarr[num][num23];
    unsigned int comb2 = combarr[denom][denom23];
    unsigned int tempways = myds23 * myds57 * comb1 * comb2;
    ways += tempways;
  }
  return ways;
}
 
int main() {
  FastInput fi;
  //FastInput fi("DIVPRO.in2");
  FastOutput fo;
  int t;
  calc23ds();
  calc57ds();
  calc0ds();
  setcomb();
  fi.getint(t);
  while (t--) {
    int l;
    fi.getint(l);
    unsigned long long v;
    fi.getull(v);
    int num = l/2;
    int denom = num;
    if (l % 2 == 1) { num++; }
    unsigned int zz = solve(v,num,denom);
    fo.putuint(zz,'\n');
  }
  fo.flush();
  return(0);
}
 
