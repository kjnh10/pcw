
def solve():
    N = int(input())
    parity = len(bin(N)) & 1 # N の深さの偶奇によって互いの戦略が変わる

    if parity:
        x = 1
        i = 0

        while x <= N:
            if not(i): # Takahashi のターン
                x = 2*x + 1 # Takahashi は右に行きたがる
                i ^= 1
            else: # Aoki のターン
                x = 2*x # Aoki は左に行きたがる
                i ^= 1

        print('Aoki' if i else 'Takahashi')
        return
    else:
        x = 1
        i = 0

        while x <= N:
            if not(i): # Takahashi のターン
                x = 2*x # Takahashi は左に行きたがる
                i ^= 1
            else: # Aoki のターン
                x = 2*x + 1 # Aoki は右に行きたがる
                i ^= 1

        print('Aoki' if i else 'Takahashi')

if __name__ == '__main__':
    solve()