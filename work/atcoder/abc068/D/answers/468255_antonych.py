def main():
    k = int(input())
    for n in range(50, 1, -1):
        clear = k // n + 1
        additional = n - k % n
        a = clear + n - 1
        if(a >= 0 and a <= 10**16 + 1000):
            lst = [a] * n
            for i in range(additional):
                m = max(lst)
                forbidden = -1
                for i, item in enumerate(lst):
                    if(item == m):
                        forbidden = i
                        lst[i] -= n
                        break
                for i in range(len(lst)):
                    if(i != forbidden):
                        lst[i] += 1
            print(n)
            print(' '.join([str(item) for item in lst]))
            return 0
main()
