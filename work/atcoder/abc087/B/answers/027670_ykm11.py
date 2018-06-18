A = int(input())
B = int(input())
C = int(input())
X = int(input())

cnt = 0
for f in range(0, A+1):
    for o in range(0, B+1):
        for hf in range(0, C+1):
            s = f*500 + o*100 + hf*50
            if s == X : cnt +=1

print(cnt)