import math

def f(t):
    return A * t + B * math.sin(C*t*math.pi)

def main():
    global A,B,C
    A,B,C= map(int,input().split())
    L,R = 0.0,200.0
    for _ in [0]*120:
        M = ( L + R ) * 0.5
        if f(M) < 100:
            L = M
        else:
            R = M
    print(L)

if __name__ == "__main__":
    main()
