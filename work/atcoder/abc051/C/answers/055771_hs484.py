sx,sy,tx,ty = map(int,input().split())
tx -= sx
ty -= sy
ans = ""
ans += "U" * ty + "R" * tx
ans += "D" * ty + "L" * tx
ans += "L" + "U"*(ty+1) + "R"*(tx+1) + "D"
ans += "R" + "D"*(ty+1) + "L"*(tx+1) + "U"
print(ans)
