# coding: utf-8
h,w=map(int,input().split())
t=[]
for i in range(h):
    t.append(list(input()))
for i in range(h):
    for j in range(w):
        if t[i][j]=='#':
            tmp=0
            if i+1<h and t[i+1][j]=='#':
                tmp+=1
            if i-1>=0 and t[i-1][j]=='#':
                tmp+=1
            if j+1<w and t[i][j+1]=='#':
                tmp+=1
            if j-1>=0 and t[i][j-1]=='#':
                tmp+=1
            if tmp==0:
                print('No')
                exit()
print('Yes')