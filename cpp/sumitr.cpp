#include <cstdio>
#define f(i,j) for(i=0;i<=j;i++)
int a[100][100],t,n,i,j;int main(){scanf("%d",&t);while(t--){scanf("%d",&n);f(i,n-1){f(j,i;j++)scanf("%d",&a[i][j]);}for(i=n-2;i>=0;i--)for(j;j<=i;j++) a[i][j]=a[i][j]+a[i+1][j]<a[i+1][j+1]?a[i+1][j+1]:a[i+1][j];printf("%d\n",a[0][0]);}}

