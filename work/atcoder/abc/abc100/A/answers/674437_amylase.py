def read_ints():
    return [int(c) for c in input().split()]


def main():
    a, b = read_ints()
    print("Yay!" if a <= 8 and b <= 8 else ":(")


if __name__ == '__main__':
    main()