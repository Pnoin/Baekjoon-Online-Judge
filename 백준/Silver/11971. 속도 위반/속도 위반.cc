#include <cstdio>

int main(){
  int n,m,a[105]={},b[105]={},x,y,count=1,total=0,max=0;
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++){
    scanf("%d%d",&x,&y);
    for(int j=count; j<count+x; j++){
      a[j]=y;
    }
    count+=x;
  }
  count=1;
  for(int i=1; i<=m; i++){
    scanf("%d%d",&x,&y);
    total=0;
    for(int j=count; j<count+x; j++){
      b[j]=y;
      if(b[j]>a[j]){
        total=b[j]-a[j];
      }
    }
    if(total>=max){
      max=total;
    }
    count+=x;
  }
  printf("%d", max);
}
