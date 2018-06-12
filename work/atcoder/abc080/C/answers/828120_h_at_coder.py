import sys
import itertools

def get_ben(time_list, shop_open_list, ben_list):
    count_list = []
    for shop_list in shop_open_list:
        count_list.append(len(list(filter(lambda i: (shop_list[i] == 1) and (time_list[i] == 1), list(range(10))))))
    res = 0
    for i, count in enumerate(count_list):
        res += ben_list[i][count]
    return res

n = int(sys.stdin.readline().strip())

shop_open_list = []
ben_list =[]

for _ in range(n):
    shop_open_list.append(list(map(int, sys.stdin.readline().strip().split(" "))))

for _ in range(n):
    ben_list.append(list(map(int, sys.stdin.readline().strip().split(" "))))

B = (0,1)
cand = []
for l in itertools.product(B, repeat = 10):
    if sum(l) == 0:
        continue
    cand.append(get_ben(l, shop_open_list, ben_list))

print(str(max(cand)))

