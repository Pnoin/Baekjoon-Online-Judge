# [Bronze II] Inflation - 35006 

[문제 링크](https://www.acmicpc.net/problem/35006) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 사칙연산

### 제출 일자

2026년 04월 28일 02:51:09

### 문제 설명

<p>In a distant magical kingdom, each wizard was assigned a fixed monthly salary upon starting their service.</p>

<p>However, there was a problem: while the wizard diligently cast spells, prices increased over the year due to inflation.</p>

<p>To curb the rapid rise in prices, the wise king announced on the first day of the first month of the year the final annual inflation rate $p$ and allowed prices to be raised only once a month: exactly one day before the wizards' salaries were paid. The wizards' salaries are paid on the last day of each month.</p>

<p>Moreover, for convenience, he established that there are only ten months in a year, and each month has thirty days. Each month, prices were to rise by exactly $p / 10$ percent of the price of goods at the <strong>beginning</strong> of the year. Thus, the cost of any good increased by exactly $p$ percent over the year.</p>

<p>The <em>current salary payment system</em> is structured as follows. On the first day of the first month of the year, a salary of $n$ gold is assigned, which they will receive at the end of each month of the year. Additionally, salaries are indexed each year: if the monthly salary in a given year is $n$ gold, and the inflation rate is $p$, then the monthly salary for the next year will be $p$ percent higher, that is, it will become $n + (np / 100)$ gold.</p>

<p>Is this an ideal solution? No! The wizards are still dissatisfied: prices rise monthly, while salaries only increase once a year. The wizards propose an alternative called the <em>progressive salary payment system</em>: on the last day of each month, the amount paid as salary has the same purchasing power that the salary of $n$ gold had on the first day of the first month of the year. In other words, for this amount, you can buy exactly the same quantity of any goods that could be purchased for $n$ gold on the first day of the first month.</p>

<p>To assess this injustice, the king has tasked you with determining, based on the wizard's monthly salary at the beginning of the year, how much money they lose over the year under the current salary payment system compared to the progressive salary payment system.</p>

### 입력 

 <p>The first line contains two integers $n$ and $p$ separated by a space: the monthly salary of a wizard in gold and the annual inflation rate ($10^3 \le n \le 10^5$; $0 \le p \le 100$).</p>

### 출력 

 <p>Output the amount that the wizard will lose this year compared to the progressive salary payment system. Remember that a year in the magical kingdom consists of ten months. The answer is considered correct if the absolute or relative error does not exceed $10^{-4}$.</p>

