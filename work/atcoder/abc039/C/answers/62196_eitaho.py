A = ["Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"]
B = "WBWBWWBWBWBW"
L = 20
S = input()

for i in range(len(A)):
    C = ""
    for x in range(L):
        C += B[(i + x) % len(B)]
    if C == S:
        print(A[i])
        break
