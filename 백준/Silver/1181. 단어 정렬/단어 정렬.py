n=int(input())
words=[]
for i in range(n):
    words.append(input())
words2=set(words)
words=list(words2)
words.sort()
words.sort(key=len)
for i in range(len(words2)):
    print(words[i])