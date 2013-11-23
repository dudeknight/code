#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;

int xc[]={-1,0,0,1};
int yc[]={0,-1,1,0};

int dp[500][500];

int main(){
	int t;cin>>t;
	while(t--){
		int r,c;cin>>r>>c;
		vector<string> g;
		for(int i=0;i<r;i++){
			string s;
			cin>>s;g.push_back(s);
		}
	
		queue<pi>q;
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(g[i][j]>='a' && g[i][j]<='z'){
					q.push(pi(i,j));
					dp[i][j]=0;
				}
				else if(g[i][j]=='.'){
					dp[i][j]=600;		
				}
			}
		}

		while(!q.empty()){
			int i=q.front().first;
			int j=q.front().second;
			char ch,ch2;
			q.pop();
			
			if(g[i][j]=='*') continue;

			ch=g[i][j];

			for(int k=0;k<4;k++){
				int x= i+xc[k];
				int y= j+yc[k];
				if(x<r &&x>=0 && y<c &&y>=0){
					if(g[x][y]=='.'){
						bool flag=true;
						for(int l=0;l<4;l++){
							if(l==3-k) continue;
							int nx=x+xc[l];
							int ny=y+yc[l];
							if(nx<r &&nx>=0 && ny<c && ny>=0){
								if(g[nx][ny]>='a' && g[nx][ny]<='z' && g[nx][ny]!=ch && dp[nx][ny]==dp[i][j]){
									flag=false;break;
								}
							}
						}
						if(flag){
							g[x][y]=ch;q.push(pi(x,y));dp[x][y]=dp[i][j]+1;
						}
						else{
							g[x][y]='*';
						}
					}
				}
			}
			
		}


		for(int i=0;i<r;i++){
			cout<<g[i]<<endl;
		}
		cout<<endl;
	}

	return 0;
}
