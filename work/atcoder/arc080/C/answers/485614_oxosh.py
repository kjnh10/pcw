# C
N = int(input())
a_list = list(map(int, input().split()))

cnt_4 = 0
cnt_2 = 0

for a in a_list:
    if a % 4 == 0:
        cnt_4 += 1
    elif a % 2 == 0:
        cnt_2 += 1
        
cnt_1 = N - cnt_4 - cnt_2

if cnt_4 >= cnt_1:
    print("Yes")
elif cnt_4 + 1 == cnt_1 and cnt_2 == 0:
    print("Yes")
else:
    print("No")