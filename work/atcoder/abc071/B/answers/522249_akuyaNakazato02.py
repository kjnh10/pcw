S = input()

alphabet = "abcdefghijklmnopqrstuvwxyz"

for alp in alphabet:
    if alp not in S:
        print(alp)
        break
else:
    print("None")