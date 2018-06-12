sa = input()
sb = input()
sc = input()

card = sa[0]
sa = sa[1:]
while 1:
	if card == "a":
		if not sa:
			print("A")
			break
		else:
			card = sa[0]
			sa = sa[1:]
	elif card == "b":
		if not sb:
			print("B")
			break
		else:
			card = sb[0]
			sb = sb[1:]
	else:
		if not sc:
			print("C")
			break
		else:
			card = sc[0]
			sc = sc[1:]
