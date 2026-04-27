/*
    지난번에는 세그트리로 inversion counting을 구현해서 풀었는데
    4157번이 이 문제를 풀 때 썼던 방법으로는 풀리는 문제가 아니였음.
    그 문제는 입력으로 들어오는 값들이 n 범위 내라는 법이 없었고, 입력으로 들어오는 숫자들이 10억까지 나오면서
    배열로 1~10억칸을 다 만들기엔 메모리가 부족했음
    값 압축을 하거나, 머지소트를 활용한 inversion counting 기법을 통해서만 풀 수 있었음.

    머지소트 공부할 때 사용한 블로그들: 
    https://seongjuk.tistory.com/entry/%EB%A8%B8%EC%A7%80-%EC%86%8C%ED%8A%B8-Merge-sort-%EB%B3%91%ED%95%A9-%EC%A0%95%EB%A0%AC%EA%B3%BC-%EB%A8%B8%EC%A7%80-%EC%86%8C%ED%8A%B8-%ED%8A%B8%EB%A6%AC-MST
    https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html
    https://blog.koderpark.dev/230

    병합정렬도 분할정복 기법으로 작동하니 따지고보면 세그트리랑 비슷한 원리라 생각하면 됨.
*/

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

int n;
ll cnt=0;

void merge_sort(vector <ll> &a, vector <ll> &tree, int start, int end) {
    if(start<end) {
        merge_sort(a,tree,start, (start+end)/2);
        merge_sort(a,tree,(start+end)/2+1, end);
        int left=start, right=(start+end)/2+1, idx=start;
        while (left<=(start+end)/2 || right<=end) {
            if (right>end || (left<=(start+end)/2 && a[left]<a[right])) {
                tree[idx++] = a[left++];
            }
            else {
                cnt+=((start+end)/2-left+1);
                tree[idx++] = a[right++];
            }
        }
        for(int i=start; i<=end; i++)
            a[i]=tree[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector <ll> a(n);
    vector <ll> tree(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    merge_sort(a,tree,0,n-1);
    cout << cnt;
}