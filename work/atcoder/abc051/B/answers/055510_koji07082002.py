def main():
    K,S = map(int,input().split())

    count = 0
    for x in range(max(0,S - 2*K), K + 1):
        for y in range(max(0,S - x - K), K + 1):
            if 0 <= S - x - y <= K:
                count += 1
    print(count)

if __name__ == "__main__":
    main()
