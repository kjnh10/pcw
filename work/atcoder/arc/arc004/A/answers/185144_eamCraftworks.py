import math

def calc(a,b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2

def main():
    n = int(input())
    ps = [list(map(int,input().split())) for _ in [0]*n]
    maxi = 0
    for a in ps:
        for b in ps:
            if maxi < calc(a,b):
                maxi = calc(a,b)
    print(math.sqrt(maxi))

if __name__ == "__main__":
    main()
