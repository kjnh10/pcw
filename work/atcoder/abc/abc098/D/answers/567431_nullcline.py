# your code goes here
N = int(input())

A = list(map(int,input().split()))

ans = 0
ans_plus = 0
l = 0
r = 0
xor_sum = A[0]
sum = A[0]
while 1:
	if xor_sum == sum:
		ans_plus += 1
		ans += ans_plus
		if r == N-1:
			break
		else:
			r += 1
		xor_sum ^= A[r]
		sum += A[r] 
	else:
		ans_plus -= 1
		xor_sum ^= A[l]
		sum -= A[l]
		l += 1

print(ans)
	
	