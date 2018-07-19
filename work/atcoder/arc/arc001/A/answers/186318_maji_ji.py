import numpy as np

N=int(input())
answers=list(input())

count=np.zeros(4)
for ans in answers:
    count[int(ans)-1]+=1

print('{0:1.0f}'.format(np.max(count)),'{0:1.0f}'.format(np.min(count)))