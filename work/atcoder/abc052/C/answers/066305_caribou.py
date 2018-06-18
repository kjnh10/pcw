from collections import Counter
def primes(n):
    pp = [True] * (n+1000)
    pp[0] = False
    pp[1] = False

    for i in range(2,n+1000):
        if pp[i]:
            for j in range(2,(n+1000)//i):
                pp[i*j] = False
    result = [i for i in range(n+1) if pp[i]]
    return result



if __name__=="__main__":
    N= int(input())

    pr = primes(N)
    counter = Counter()
    for p in pr:
        x = p
        while x <= N:
            counter[p] += N//x
            x *= p
    result = 1
    for x in counter.values():
        result = (result * (x+1)) % 1000000007
    print(result)
