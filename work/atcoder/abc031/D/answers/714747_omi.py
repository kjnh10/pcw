from itertools import *
def main():
    k,n = map(int,input().split())
    clues = [input().split() for _ in range(n)]
    #print(clues)
    for i in product(range(1,4), repeat=k):
        for j in clues:
            #print(list(map(lambda x: i[x-1],map(int,list(j[0])))))
            if sum(map(lambda x: i[x-1],map(int,list(j[0])))) != len(j[1]):
                break
        else:
            #print(i)
            ret = [""]*k
            for l in clues:
                #print(l)
                tmp = 0
                for m in map(int,list(l[0])):
                    #print(m)
                    query = l[1][tmp:tmp+i[m-1]]
                    #print(ret)
                    if ret[m-1] == "":
                        ret[m-1] = query
                    elif ret[m-1] != query:
                        #print(l,m)
                        break
                    tmp += i[m-1]

                if tmp != len(l[1]):
                    break

            else:
                for ln in ret:
                    print(ln)
                return 0

main()
