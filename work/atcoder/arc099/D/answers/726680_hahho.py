K = int(input())
d = 0
n = 1
while K > 0:
  if ((n+1)*10**d-1)*(sum(map(int,str(n+1)))+9*d) <= ((n+2)*10**d-1)*(sum(map(int,str(n)))+9*d):
    print(n,'9'*d, sep='')
    K -= 1
    n += 1
  else:
    d += 1
    n = (n+1)//10