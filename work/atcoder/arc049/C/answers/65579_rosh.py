s = input()
a, b, c, d = map(int, input().split())
print('{}"{}"{}"{}"{}'.format(s[0:a], s[a:b], s[b:c], s[c:d], s[d:]))
