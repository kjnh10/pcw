n = int(input())
pow2 = [2 ** item for item in range(10)]
for item in pow2[::-1]:
    if(item <= n):
        print(item)
        break
