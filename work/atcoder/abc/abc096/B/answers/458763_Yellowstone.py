a,b,c=map(int,input().split())
k = int(input())
print(a+b+c + pow(2,k)*max(a,b,c)-max(a,b,c))