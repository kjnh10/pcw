
def solve():
    s = input()
    N = int(input())

    cnt = 0

    for i in range(5):
        for j in range(5):
            cnt += 1

            if cnt == N:
                print(''.join([s[i], s[j]]))
                return

if __name__ == '__main__':
    solve()