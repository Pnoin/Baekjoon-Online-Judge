# [Gold V] CCC Word Hunt - 28308 

[문제 링크](https://www.acmicpc.net/problem/28308) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

구현, 그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 깊이 우선 탐색

### 제출 일자

2026년 04월 28일 02:51:09

### 문제 설명

<p>In the CCC Word Hunt, words are hidden in a grid of letters. The letters of a hidden word always appear in order on horizontal, vertical, or diagonal line segments in one of two ways. One way is for the letters of a word to appear on one line segment. The other way is for the letters of a word to appear on one line segment up to some letter and then on a second line segment that forms a right angle at this letter.</p>

<p>Given a grid of letters and a single word to search for, your job is to determine the number of times that particular word is hidden in the grid.</p>

### 입력 

 <p>The first line of input will contain a string of distinct uppercase letters, $W$, representing the word you are to search for in the grid. The length of $W$ will be at least two.</p>

<p>The second line of input will be an integer $R$ $(1 \le R \le 100)$, where $R$ is the number of rows in the grid.</p>

<p>The third line of input will be an integer $C$ $(1 \le C \le 100)$, where $C$ is the number of columns in the grid.</p>

<p>The remaining input will provide the letters in the grid. It will consist of $R$ lines, where each line contains $C$ uppercase letters separated by single spaces.</p>

### 출력 

 <p>The output will consist of a single non-negative integer $H$, representing the number of times the word is hidden in the grid.</p>

