h,w = map(int, input().split())
can = []
if h%3 == 0 or w%3 == 0:
    can.append(0)
if h > 3:
    can.append(w)
if w > 3:
    can.append(h)

for a in range(w//3, w//2+1):
    size = [h * a]
    if h%2 == 0:
        size.append(h//2 * (w-a))
        size.append(h//2 * (w-a))
    else:
        size.append(h//2 * (w-a))
        size.append((h//2 + 1) * (w-a))
    can.append(max(size) - min(size))

for a in range(h//3, h//2+1):
    size = [w * a]
    if w%2 == 0:
        size.append(w//2 * (h-a))
        size.append(w//2 * (h-a))
    else:
        size.append(w//2 * (h-a))
        size.append((w//2 + 1) * (h-a))
    can.append(max(size) - min(size))
print(min(can))