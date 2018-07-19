if __name__ == '__main__':
    A, B, K, L = map(int, input().split())
    if A * L <= B:
        print(K // A + 1)
    else:
        l = K // L
        a = K - l * L
        print(min((l + 1) * B, a * A + l * B))
