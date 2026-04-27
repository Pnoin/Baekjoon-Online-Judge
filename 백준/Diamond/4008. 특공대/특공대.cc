/*
    <메모>
    2024.07.14
    특공대의 조정된 전투력 = 이차함수 (최고차항의 계수가 음수이기 때문에 아래로 오목한)
    각 계수인 a,b,c는 주어진다고 함
    N명의 사람들의 능력치가 순서대로 주어졌을 때 연속한 사람들끼리 각 능력치를 함수에 넣었을 때 나오는 값들을 더했을 때 나오는 최댓값을 구하라

    일단 나이브하게 점화식을 세워보면 
    우선 연속된 부분의 능력치들에 대한 연산을 진행함으로 누적합 배열을 하나 만들어 놓고 사용하자
    임의의 자연수 i에 대하여, i보다 작은 모든 자연수 j에 대해 
    dp[j]+a*(prefix_sum[i]-prefix_sum[j])*(prefix_sum[i]-prefix_sum[j])+b*(prefix_sum[i]-prefix_sum[j])+c를 계산하고
    이 중에서 나오는 최댓값을 dp[i]에 저장하는 방식으로 하면 될 것이다


    2024.07.16
    일단 CHT가 적용될려면 일차함수 꼴로 변환하였을 때 기울기가 단조 증가하거나 감소해야하는데,
    이 문제에서 찾으라는 값이 최댓값이기 때문에 함수가 단조 증가 꼴이여야함. 
    위의 점화식을 풀어서 적어보면    
    dp[j]+a*(prefix_sum[i]-prefix_sum[j])*(prefix_sum[i]-prefix_sum[j])+b*(prefix_sum[i]-prefix_sum[j])+c
    = 
    dp[j] + a * (prefix_sum[i]^2 - 2*prefix_sum[i]*prefix_sum[j] + prefix_sum[j]^2) + b*(prefix_sum[i] - prefix_sum[j]) + c
    =
    dp[j] + a*prefix_sum[i]^2 - 2*a*prefix_sum[i]*prefix_sum[j] + a*prefix_sum[j]^2 + b*prefix_sum[i] - b*prefix_sum[j] + c

    저 식으로 만들 수 있는 최댓값을 찾으면 되는데, 인덱스가 i인 항은 i에 대하여 항상 고정된 값을 가지기 때문에 사실상 j가 인덱스인 항에 대해서만 max를 씌우면 된다.
    그러면
    max(dp[j] - 2*a*prefix_sum[i]*prefix_sum[j] + a*prefix_sum[j]^2 - b*prefix_sum[j]) + a*prefix_sum[i]^2 + b*prefix_sum[i] + c로 다시 쓸 수 있음

    CHT 일차함수의 기본꼴: A[i]*B[j]+C[j]
    + a*prefix_sum[i]^2 + b*prefix_sum[i] + c는 j 변수와 무관한 상수로 취급한다 쳤을 때, 
    일단 문제에서 a는 항상 음수로 주어진다고 함
    각 사람의 능력치는 양수로 주어진다고 했기 때문에 prefix_sum의 모든 값들도 다 양수일 것임
    즉, -2*a는 항상 양수고, 거기에 누적합을 곱한 것도 항상 양수임 
    또한 누적합 배열은 인덱스가 증가할수록 항상 커짐 (단조 증가함)
    때문에 일차 함수가 항상 단조 증가한다는 걸 알 수 있고, 때문에 CHT로 최댓값을 구하는 것이 가능해짐.

    즉, -2*a*prefix_sum[i]를 A[i]로 잡고, 거기에 곱해질 prefix_sum[j]를 B[j]라고 두면, 
    max함수 내의 남은 다른 항들인 a*prefix_sum[j]^2 - b*prefix_sum[j] + dp[j]는 j라는 변수에 대해 값이 결정되므로, 절편 역할을 할 C[j]로 묶는게 가능해진다.


    1차 시도 WA: 4%에 틀림 
    마침 질문 게시판에 4% WA 원인 관련된 글이 있었음: https://www.acmicpc.net/board/view/135706
    
    지속적인 4% WA: 음수 실수 정수 변환은 나름 고친 거 같은데 계속 오류가 뜨길래 이게 내 점화식에 오류가 있나 검산함
    점화식을 약간 바꿈
    B[j]를 -2*a*prefix_sum[j]로, A[i]를 prefix_sum[i]로 바꿈 
    C[j]는 여전히 a*prefix_sum[j]^2 - b*prefix_sum[j] + dp[j]
    그 외의 상수는 a*prefix_sum[i]^2 + b*prefix_sum[i] + c
    사실 수학적으로 바뀐 건 없다만 구현에서 약간 바뀜

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <time.h>   
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

ll dp[1000005]={},prefix_sum[1000005]={},f1[1000005]={},f2[1000005]={};
int cnt=0,n,a,b,c;
// f1이 기울기, f2가 절편

ld intersect(ll x, ll y){
    ld temp1=(f2[y]-f2[x]),temp2=(f1[x]-f1[y]);
    return (ld)(temp1/temp2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> a >> b >> c >> prefix_sum[0];
    for(int i=1; i<n; i++){
        cin >> prefix_sum[i];
        prefix_sum[i]+=prefix_sum[i-1];
    }
    dp[0]=a*prefix_sum[0]*prefix_sum[0]+b*prefix_sum[0]+c;
    f1[0]=-2*a*prefix_sum[0];
    f2[0]=a*prefix_sum[0]*prefix_sum[0]-b*prefix_sum[0]+dp[0];
    int Hull_Points=1;
    for(int i=1; i<n; i++){
        dp[i]=(a*prefix_sum[i]*prefix_sum[i])+(b*prefix_sum[i])+c;
    }
    for(int i=1; i<n; i++){
        while(true){
            if(cnt+1>=Hull_Points || intersect(cnt,cnt+1)>(ld)prefix_sum[i]){
                break;
            }
            cnt++;
        }
        dp[i]+=max((f1[cnt]*prefix_sum[i])+f2[cnt],(ll)0);
        f1[Hull_Points]=-2*a*prefix_sum[i];
        f2[Hull_Points]=a*prefix_sum[i]*prefix_sum[i]-b*prefix_sum[i]+dp[i];
        while(true){
            if(intersect(Hull_Points-1,Hull_Points-2)<=intersect(Hull_Points-1,Hull_Points) || Hull_Points<=1){
                break;
            }
            f1[Hull_Points-1]=f1[Hull_Points];
            f2[Hull_Points-1]=f2[Hull_Points];
            Hull_Points--;
        }
        Hull_Points++;
    }
    cout << dp[n-1];

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
