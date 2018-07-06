s=input()
ks="WBWBWWBWBWBW"
vs=["Do", "Re", "Mi", "Fa", "So", "La", "Si"]
for i in range(7):
    if (ks == s[:12]):
        print(vs[i])
        break
    ks = ks[1:] + ks[0]
    while ks[0] != 'W':
        ks = ks[1:] + ks[0]