h, w = tuple(int(x) for x in input().split())

c_arr = [input() for _ in range(h)]

for i in range(2 * h):
    print(c_arr[i // 2])