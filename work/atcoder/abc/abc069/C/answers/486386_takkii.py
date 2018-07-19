n = input()
a_list = input().split()
a_list = [int(a) for a in a_list]

fours = 0
twos = 0
others = 0

for a in a_list:
    if a % 4 ==0:
        fours += 1
    elif a % 2 == 0:
        twos += 1
    else:
        others += 1

if others <= fours:
    print("Yes")
elif others-1 == fours and twos==0:
    print("Yes")
else:
    print("No")
