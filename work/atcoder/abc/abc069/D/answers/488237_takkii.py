h,w = input().split()
h = int(h)
w = int(w)
n = int(input())
a_list = input().split()
a_list = [int(a) for a in a_list]

c_list = []
for i,a in enumerate(a_list):
    for j in range(a):
        c_list.append(i+1)
        
for i in range(h):
    p_list = c_list[w*i:w*(i+1)]
    p_list = [str(p) for p in p_list]
    if i % 2 == 0:
        print(" ".join(p_list))
    else:
        print(" ".join(p_list[::-1]))