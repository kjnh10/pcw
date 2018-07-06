
def solve():
    N = int(input())
    m = (N >> 1) + 1

    if not (len(bin(m)) & 1):
        m2 = bin(m)[3:]

        for i, b in enumerate(m2):
            if i & 1:
                if b == '1':
                    print('Aoki')
                    return
            else:
                if b == '0':
                    print('Takahashi')
                    return

        print('Takahashi')
        return

    m2 = bin(m)[3:]

    for i, b in enumerate(m2):
        if i & 1:
            if b == '0':
                print('Aoki')
                return
        else:
            if b == '1':
                print('Takahashi')
                return

    print('Aoki')

if __name__ == '__main__':
    solve()