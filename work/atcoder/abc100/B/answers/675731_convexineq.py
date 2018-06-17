# coding: utf-8
# Your code here!

d,n = [int(i) for i in input().split()]

if n < 100:
	print(n*(100**d))
else:
  	print((n+1)*(100**d))
  