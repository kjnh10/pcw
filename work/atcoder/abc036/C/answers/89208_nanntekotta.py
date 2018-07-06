'''
cat C_test1.txt | python3 C.py
'''

N = int(input())
data = []
for i in range(N):
    a = int(input())
    data.append(a)

kind = set(data)
kind = list(kind)
kind.sort()

assyuku = {}
j = 0
for i in kind:
    assyuku[i] = j
    j += 1

for i in data:
    print(assyuku[i])
