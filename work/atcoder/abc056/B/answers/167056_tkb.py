w, a, b = map(int, input().split(" "))
al = a
ar = a+w
bl = b
br = b+w
if bl <= ar and ar <= br:
    print(0)
elif a<b:
    print(bl-ar)
else:
    print(al-br)