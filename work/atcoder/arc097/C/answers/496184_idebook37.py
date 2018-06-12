S = input()
K = int(input())
n = len(S)

ans = []
st = set()

for i in range(n):
    for j in range(i + 1, min(n + 1, i + 1 + K)):
        sub = S[i:j]
        # print(sub)
        if sub in st:
            continue
        st.add(sub)
        ans.append(sub)
        ans.sort()
        # print(ans)
        if len(ans) > K:
            ans = ans[:K]

print(ans[-1])
