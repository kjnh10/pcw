def eratosthenes_generator():
    n = 3
    h = {}
    while True:
        m = n
        if n in h:
            b = h[n]
            m += 2 * b
            while m in h:
                m += 2 * b
            h[m] = b
            del h[n]
        else:
            m += 2 * n
            while m in h:
                m += 2 * n
            h[m] = n
            yield n
        n += 2


n = int(input())
i = 0
buf = []
for k in eratosthenes_generator():
    if k % 5 == 1:
        buf.append(k)
        i += 1
        if i >= n:
            break
print(*buf)
