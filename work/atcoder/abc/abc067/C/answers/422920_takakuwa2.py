N = int(input())
A =list(map(int,input().split()))

tmp=0
sum_list = [0]
for i in range(N):
    tmp +=A[i]
    sum_list.append(tmp)

#print(sum_list)

diff =9999999999999
for i in range(1,N):
    diff = min(diff , abs( sum_list[-1]-2*sum_list[i]  ))

print(diff)