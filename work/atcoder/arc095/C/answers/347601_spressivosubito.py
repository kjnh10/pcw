N = int(input())
arr = list(map(int, input().split()))
arr2 = sorted(arr)

mean1 = arr2[N//2-1]
mean2 = arr2[N//2]

for a in arr:
  if a <= mean1:
    print(mean2)
  else:
    print(mean1)