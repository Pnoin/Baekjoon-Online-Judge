# [Silver III] Triangle Partition - 18979 

[문제 링크](https://www.acmicpc.net/problem/18979) 

### 성능 요약

메모리: 7880 KB, 시간: 8 ms

### 분류

정렬, 기하학, 해 구성하기

### 제출 일자

2026년 04월 28일 02:51:09

### 문제 설명

<p>Chiaki has $3n$ points $p_1,p_2,\dots,p_{3n}$. It is guaranteed that no three points are collinear.</p>

<p>Chiaki would like to construct $n$ disjoint triangles where each vertex comes from the $3n$ points.</p>

### 입력 

 <p>There are multiple test cases. The first line of input contains an integer $T$, indicating the number of test cases. For each test case:</p>

<p>The first line contains an integer $n$ ($1 \le n \le 1000$) -- the number of triangle to construct.</p>

<p>Each of the next $3n$ lines contains two integers $x_i$ and $y_i$ ($-10^9 \le x_i, y_i \le 10^9$).</p>

<p>It is guaranteed that the sum of all $n$ does not exceed $10^4$.</p>

### 출력 

 <p>For each test case, output $n$ lines contain three integers $a_i,b_i,c_i$ ($1 \le a_i,b_i,c_i \le 3n$) each denoting the indices of points the $i$-th triangle use. If there are multiple solutions, you can output any of them.</p>

