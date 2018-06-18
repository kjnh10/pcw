import sys
import math

S = list(map(int,input().split()))

A = list(map(int,input().split()))

X=S[1]
Y=S[2]

if S[0]==1:
	print(int(math.fabs(A[-1]-Y)))
else:
	r1=math.fabs(A[-1]-Y)
	r2=math.fabs(A[-2]-A[-1])

	if r1<r2:
		print(int(r2))
	else:
		print(int(r1))
