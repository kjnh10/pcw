from collections import defaultdict


def main():
    A, B = map(int, input().split())

    if A == 1:
        A += 100
    if B == 1:
        B += 100

    if A == B:
        print("Draw")
    elif A > B:
        print("Alice")
    else:
        print("Bob")


if __name__ == '__main__':
    main()
