W, a, b = map(int, input().split())
diff = abs(a-b)
print(max(0, diff-W))