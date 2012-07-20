#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ed{
	int x;int y;int z;
};


int k[50][50];
int bld[50][50];
int dst[50][50];

int map[100000],n;
ed v[400000];

int a[100000];
int wt[100000];

long long res;

bool comp(ed a,ed b){
	if(a.z<b.z) return true;
	else return false;
}

int parent (int x){
        while(x!=a[x]){
                int temp=a[x];
                a[x]=a[a[x]];
                x=temp;

        }
        return x;
}


class KingdomReorganization {
public:
	int getCost(vector <string>, vector <string>, vector <string>);
};

int KingdomReorganization::getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
	n=kingdom.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			k[i][j]=kingdom[i][j]-'0';
			if(build[i][j]>='A'	&& build[i][j]<='Z'){
				bld[i][j]=build[i][j]-'A';
			}
			else{
				bld[i][j]=build[i][j]-'a'+26;
			}
			if(destroy[i][j]>='A' && destroy[i][j]<='Z'){
				dst[i][j]=-1*(destroy[i][j]-'A');
			}
			else{
				dst[i][j]=-1*(destroy[i][j]-'a'+26);
			}
		}
	}
	int cur=0;
	int dst_sum=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(bld[i][j]){
				v[cur].x=i;v[cur].y=j;v[cur].z=dst[i][j];
				dst_sum-=dst[i][j];
			}
			else{
				v[cur].x=i;v[cur].y=j;v[cur].z=bld[i][j];
				
			}
			cur++;
		}
	}
	
	sort(v,v+cur,comp);

	for(int i=0;i<n;i++){
			a[i]=i;wt[i]=1;
	}
	int count=0;
	int i=0,main_res;
		//cout<<"dbg\n";
	while(count<n-1){
	
		int t1,t2;
		t1=parent(a[v[i].x]);
		t2=parent(a[v[i].y]);
		//cout<<i<<" "<<t1<<" "<<t2<<" "<<count<<endl;
		if(t1!=t2){
				res+=v[i].z;
				dst_sum+=v[i].z;
				if(wt[t1]<wt[t2]){
					a[t1]=t2;
					wt[t2]+=wt[t1];
				}
				else{
					a[t2]=t1;
					wt[t1]+=wt[t2];
				}
				count++;
		}	
		i++;
	}
	
	return dst_sum;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!