from collections import deque


def solve(k):
    que = deque([(1, 1)])
    checked = set()
    while True:
        cost, num = que.popleft()
        if num == 0 or num == k:
            return cost
        if num in checked:
            continue
        checked.add(num)
        que.appendleft((cost, num * 10 % k))
        que.append((cost + 1, num + 1))


print(solve(int(input())))
