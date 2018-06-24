N,K=[int(i) for i in input().split()]
A=[int(i) for i in input().split()]

freq=[0 for i in range(N+1)]
for i in range(N):
    freq[A[i]]+=1
# print(freq)

sorted_freq=sorted(freq)
# print(sorted_freq)

count=0
for i in range(1,N-K+1):
    count+=sorted_freq[i]
print(count)
