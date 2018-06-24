N=int(input())
a=[int(i) for i in input().split()]

#最大値と最小値の検索
max_a=-100000000
min_a=100000000
max_index=-1
min_index=-1
for i in range(N):
    if a[i] > max_a:
        max_a=a[i]
        max_index=i
    if a[i] < min_a:
        min_a=a[i]
        min_index=i

tezyun=[]
#全て同じ数
if min_a==max_a:
    None
#全てのaiが0以上
elif min_a>=0:
    for i in range(1,N):
        tezyun.append([i,i+1])
#全てのaiが0以下
elif max_a<=0:
    for i in reversed(range(1,N)):
        tezyun.append([i+1,i])
#正負がまじっている
else:
    count=0
    if abs(max_a)>=abs(min_a):
        for i in range(N):
            if a[i]<0:
                a[i]=a[i]+a[max_index]
                tezyun.append([max_index+1,i+1])
                count+=1
        for i in range(1,N):
            tezyun.append([i,i+1])
    elif abs(max_a)<abs(min_a):
        for i in range(N):
            if a[i]>0:
                a[i]=a[i]+a[min_index]
                tezyun.append([min_index+1,i+1])
                count+=1
        for i in reversed(range(1,N)):
            tezyun.append([i+1,i])

print(len(tezyun))
for te in tezyun:
    print(te[0],te[1])
