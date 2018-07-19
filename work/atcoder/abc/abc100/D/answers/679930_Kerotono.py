#!python
# -*- coding: utf-8 -*-


def main():
    N, M = map(int, input().split())
    cakes = []

    for i in range(N):
        cakes.append(list(map(int, input().split())))

    ANS = 0

    for i in range(2 ** 3):
        x = i % 2 or -1
        y = i // 2 % 2 or -1
        z = i // 4 % 2 or -1

        points = []
        for c_x, c_y, c_z in cakes:
            points.append(c_x * x + c_y * y + c_z * z)
        points.sort(reverse=True)
        s = sum(points[:M])

        if ANS < s:
            ANS = s

    print(ANS)


if __name__ == '__main__':
    main()
