#include <cstdio>

int main(){
  int n,s[105]={},e[105]={},max=0,a[1005]={},copya[1005]={};   /// a배열은 각 시간대별로 몇명의 lifeguard들이 서있는지를 저장
  scanf("%d", &n);                                             /// lifeguard 몇명인지 입력받기
  for(int i=0; i<n; i++){
    scanf("%d%d",&s[i],&e[i]);                                 /// 각 lifeguard들의 일하는 시간 범위 s(start 시간대)와 e(end 시간대)를 받음
    for(int j=s[i]; j<e[i]; j++){                              /// 시간대의 범위를 array로 구현. 이때, 다음 for문에서 초기화 용도로 쓸 복사본도 만듬
      a[j]++;                                                  /// 원본
      copya[j]++;                                              /// 복사본
    }
  }
  for(int j=0; j<n; j++){                                    /// lifeguard 각각 한 명씩 해고 됬을 때 어떻게 될지 생각해보자
    int total=0;                                             /// j번째 lifeguard가 해고되는 케이스에서 나머지 lifeguard들이 1명이라도 서있는 시간대
    for(int k=0; k<1005; k++){                               /// 반복문 돌릴 때마다 array 초기화 시켜주기 (경우의 수를 보는거니까)
      a[k]=copya[k]; 
    }
    for(int k=s[j]; k<e[j]; k++){                            /// 원래 j번재 lifeguard가 일하던 시간대를 배열에서 빼주자
      a[k]--;
    }
    for(int k=0; k<1005; k++){                               /// 전체 배열을 한 번씩 싹 돌려서 1명이라도 lifeguard를 서는 시간대를 total값에 +1하자
      if(a[k]>0){
        total++;
      }
    }
    if(total>max){                                           /// 각 반복문 케이스 돌릴 때마다 max값 갱신하기
      max=total;
    }
  }
  printf("%d", max);                                         /// max 출력. 끝
}