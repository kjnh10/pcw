from collections import defaultdict


def main():
    N, M = map(int, input().split())
    ans = min(N, M // 2)
    N -= ans
    M -= (ans * 2)

    if M >= 4:
        ans += M // 4
    print(ans)

if __name__ == '__main__':
    main()
