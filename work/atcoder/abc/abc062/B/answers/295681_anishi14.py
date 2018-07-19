# coding: utf-8
# Here your code !
h,w=map(int,input().split())
data=['#'*(w+2)]
for i in range(h):
    data.append('#'+input()+"#")
data.append('#'*(w+2))
print('\n'.join(data))