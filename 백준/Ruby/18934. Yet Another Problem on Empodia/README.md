# [Ruby V] Yet Another Problem on Empodia - 18934 

[문제 링크](https://www.acmicpc.net/problem/18934) 

### 성능 요약

메모리: 34592 KB, 시간: 128 ms

### 분류

수학, 다이나믹 프로그래밍

### 제출 일자

2026년 04월 28일 02:51:09

### 문제 설명

<p>길이 $N$의 순열 $p_1, p_2, \ldots, p_N$ 에 대해, 어떠한 연속 부분 수열 $p_l, p_{l + 1}, \ldots, p_r$ 에 대해 $max_{k = l}^{r} p_k - min_{k = l}^{r} p_k = r - l$ 이 성립한다면 이를 <strong>프레임 구간</strong> (framed interval) 이라고 부른다. 예를 들어 [7, 8, 9], [3, 1, 5, 4, 2], [4, 3], [2] 은 구간이다. [3, 5], [5, 3] 은 구간이 아니다.</p>

<p>길이 $N$의 순열 $p$ 와 두 정수 $1 \le l \le r \le N$ 이 주어졌을 때, $f(p, l, r)$ 은 $p_l, p_{l + 1}, \ldots, p_r$ 이 프레임 구간이면 참이고, 아니면 거짓이다.</p>

<p>길이가 $N$인 두 순열 $P, Q$ 가 주어졌을 때, 모든 $1 \le i \le j \le N$ 에 대해서 $f(P, i, j) \iff f(Q, i, j)$ 가 항상 만족한다면 $P, Q$ 를 <strong>프레임 구간 동형</strong> (framed interval isomorphic) 이라고 정의한다. </p>

<p>프레임 구간 동형 관계는 길이가 $N$인 모든 순열들간의 동치 관계 (equivalence relationship) 이다. 길이 $1 \le i \le N$ 의 모든 순열을 구간 동형 관계로 연관시켰을 때, 동치계 (equivalence class) 의 개수를 소수 $P$로 나눈 나머지를 모든 $i$ 에 대해 출력하라. </p>

### 입력 

 <p>첫 번째 줄에 두 정수 $N, P$ 가 주어진다. ($1 \le N \le 5000, 10^8 \le P \le 10^9$). $P$ 는 소수이다.</p>

### 출력 

 <p>$N$ 개의 줄을 출력하라. 이 중 $i$ 번째 줄에는, 길이 $i$ 인 모든 순열의 동치계의 개수를 $P$ 로 나눈 나머지가 출력되어야 한다.</p>

