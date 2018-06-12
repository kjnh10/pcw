s = input()
alph = [chr(i) for i in range(97,97+26)]

for i in alph:
    if i not in s:
        print(i)
        break
    if i=='z':
        print("None")
