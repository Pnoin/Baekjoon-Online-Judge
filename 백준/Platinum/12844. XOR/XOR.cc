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

void seg_tree(vector <ll> &a, vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]^tree[node*2+1];
    }
}

/// 느리게 갱신
void lazy_propagation(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end) {
    if(lazy[node]!=0){
        /*
            1. 0에다가 아무 숫자 xor하면 그 숫자 그대로.
            2. xor은 순서와 상관없이 한 번에 다 처리해도 됨 (ex. (6 xor 5) xor 4 == 6 xor (5 xor 4))
            3. 어떤 숫자를 같은 숫자로 xor하면 0이 나옴

            여기서 1번과 3번 공식을 생각해보자.
            x라는 수에 y를 여러번 xor한다고 치면, y를 짝수 번 xor 할 경우 0이 될 것이다.
            반대로 홀수 번 xor한다고 치면 0 xor y로 인해 y 그 자체가 반환될 것이다. 
            따라서 (end-start+1)만큼 일일이 xor을 돌릴 필요 없고,
            (end-start+1)의 값이 홀수인지 짝수인지를 가지고 O(1)만에 y를 여러번 xor한 최종값을 알 수 있다.
        */
        if(((end-start+1))%2==1){
            tree[node]^=lazy[node];
        }
        if (start!=end) { ///리프 노드가 아닐 경우
            /// 자식 노드에게 전파
            lazy[node*2]^=lazy[node];
            lazy[node*2+1]^=lazy[node];
        }
        /// 전파 끝
        lazy[node]=0;
    }
}

/// 업데이트
void update(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right, ll val){
    lazy_propagation(tree, lazy, node, start, end);
    if(right < start || left > end){
        return;
    }
    /*
        특정 노드의 값을 바꾸는 게 아니라 특정 구간의 값을 바꾸는 거기 때문에 start==end일 때를 보는게 아니라 left<=start && right>=end인 구간을 봐야함.
        left랑 right는 (바꾸고 싶은 구간) 고정이고, 이분탐색마냥 start랑 end만 계속 바뀜 
        즉, left <= start && right >= end 이라는 건, start와 end가 left와 right 범위 안에 들어왓다는 거니까
        여기가 이제 '느리게 갱신' 받아야하는 구간이 되었다는 것
    */
    if(left<=start && right>=end){
        lazy[node]^=val;
        lazy_propagation(tree, lazy, node, start, end);
        return;
    }
    update(tree, lazy, node*2, start, (start+end)/2, left, right, val);
    update(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node]=tree[node*2]^tree[node*2+1];
}

/// 쿼리
ll query(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right){
    lazy_propagation(tree, lazy, node, start, end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,lazy,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,lazy,node*2+1,(start+end)/2+1,end,left,right);
    return left_s^right_s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /// 세그 트리 생성
    cin >> n;
    int h=(int)ceil(log2(n));
    int tree_size = (1 << (h+2));
    vector <ll> a(n);
    vector <ll> tree(tree_size);
    vector <ll> lazy(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(a,tree,1,0,n);
    /// 쿼리 입력 받기 시작
    cin >> m;
    for(int i=0; i<m; i++){
        int ck;
        cin >> ck;
        /// 업데이트
        if(ck==1){
            int x,y;
            ll z;
            cin >> x >> y >> z;
            update(tree, lazy, 1, 0, n, x, y, z);
        }
        /// 쿼리
        else if(ck==2){
            int xx,yy; 
            cin >> xx >> yy;
            cout << query(tree, lazy, 1, 0, n, xx, yy) << '\n';
        }
    }
}