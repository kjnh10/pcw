n = int(input())
al = input().split()

odd = al[1::2]
even = al[0::2]
odd.reverse()
r = odd + even

if(n%2 == 1):
    r.reverse()

print(" ".join(r))