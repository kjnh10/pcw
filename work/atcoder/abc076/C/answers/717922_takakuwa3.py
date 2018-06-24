Sp = input()
T= input()
flag =False
ans_list = []
for i,s in enumerate(Sp):
    if i> len(Sp) - len(T):
        break
    for j,t in enumerate(T):
        if Sp[i+j]==t or Sp[i+j] =="?":
            flag=True
            continue
        else:
            flag =False
            break
    if flag:
        ans_list.append(i)

#print(ans_list)
n_ans_list = []
for i in ans_list:
    n_ans_list.append(
        (Sp[:i]+ T+Sp[i+len(T):]).replace("?","a"))
#print(n_ans_list)
n_ans_list.sort()
if n_ans_list:
    print(n_ans_list[0])
else:
    print("UNRESTORABLE")