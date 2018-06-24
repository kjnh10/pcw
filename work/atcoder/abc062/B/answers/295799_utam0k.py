H, W = map(int, input().split())
h = H+2
w = W+2
print("#"*w)
for i in range(H):
    hoge = input()
    print("#" + hoge + "#")
print("#"*w)
