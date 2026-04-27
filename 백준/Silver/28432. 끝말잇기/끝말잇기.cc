#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,m;
string arr[105]={},brr[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int idx;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]=="?"){
            idx=i;
        }
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> brr[i];
        for(int j=0; j<n; j++){
            if(brr[i]==arr[j]){
                brr[i]="...";
                break;
            }
        }
    }
    string ans;
    if(n==1){
      cout << brr[0];
      return 0;
    }
    if(idx==n-1){ ///arr 배열의 마지막 단어면 다음 단어가 없음
        int previous_size=arr[idx-1].size();
        char start=arr[idx-1][previous_size-1];  ///전단어의 마지막 글자
        for(int i=0; i<m; i++){
            if(brr[i][0]==start){ ///해당 단어의 첫글자
                ans=brr[i];
                break;
            }
        }
    }
    else if(idx==0){ ///1번째면 전단어가 없음
        char end=arr[1][0]; ///2번째 단어의 첫글자
        for(int i=0; i<m; i++){
            if(brr[i][brr[i].size()-1]==end){
                ans=brr[i];
                break;
            }
        }
    }
    else{
        int previous_size=arr[idx-1].size();
        char start=arr[idx-1][previous_size-1]; /// 전단어의 마지막 글자
        char end=arr[idx+1][0]; /// 다음 단어의 첫글자
        for(int i=0; i<m; i++){
            if(brr[i][brr[i].size()-1]==end && brr[i][0]==start){
                ans=brr[i];
                break;
            }
        }
    }
    cout << ans;
}