# [Bronze III] Mõttemeister - 7181 

[문제 링크](https://www.acmicpc.net/problem/7181) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

구현

### 제출 일자

2026년 04월 28일 02:51:09

### 문제 설명

<p>Mõttemeister on kahe mängija lauamäng. Esimene mängija mõtleb salajase 4-kohalise arvu ja teine hakkab seda ära arvama.</p>

<p>Igal käigul pakub arvaja 4-kohalise arvu. Esimene mängija vastab kahe arvuga $A$ ja $B$, kus $A$ näitab, mitu õiget numbrit oli pakutud arvus, ning $B$, mitu nendest paiknesid õigel kohal.</p>

<p>Seejärel teeb arvaja uue pakkumise ning mäng jätkub, kuni arvaja arvab salajase arvu ära või käikude arv ületab teatud piiri.</p>

<p>Näiteks olgu salajane arv 5247. Pakkumisele 1234 oleks vastus 2 (numbrid 2 ja 4 on õiged) ja 1 (number 2 on õige koha peal).</p>

<p>Kui pakkumises on korduvaid numbreid, siis loetakse iga numbrit õigeks ainult niimitu korda, kuimitu eksemplari on seda numbrit salajases arvus.</p>

<p>Kirjuta programm, mis etteantud salajasele arvule ja pakkumisele leiab õige vastuse.</p>

### 입력 

 <p>Tekstifaili esimesel real on salajane 4-kohaline arv. Teisel real on täisarv $N$ ($1 \le N \le 10\,000$). Järgmisel $N$ real on pakutavad 4-kohalised arvud.</p>

### 출력 

 <p>Tekstifaili väljastada $N$ rida, igal real kaks täisarvu $A$ ja $B$, kus $A$ ($0 \le A \le 4$) on vastavas pakkumises olevate õigete numbrite arv ning $B$ ($0 \le B \le A$) on sealhulgas õigel kohal olevate numbrite arv.</p>

