#include <cstdio>

int main(){
  int n,m,arr[301][301]={};
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  int q,a[10005]={},b[10005]={},c[10005]={},d[10005]={};
  scanf("%d", &q);
  for(int i=1; i<=q; i++){
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
  }
  for(int i=1; i<=q; i++){
    int sum=0;
    int w=a[i], x=b[i], y=c[i], z=d[i];
    for(int j=w; j<=y; j++){
      for(int k=x; k<=z; k++){
        sum=sum+arr[j][k];
      }
    }
    printf("%d\n",sum);
  }
}