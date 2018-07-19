S = input()

N = len(S)
setS = set(list(S))
if N == len(setS):
    print("yes")
else:
    print("no")
