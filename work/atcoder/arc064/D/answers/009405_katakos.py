s = input()
print('First' if (len(s) - (s[0] == s[-1])) & 1 else 'Second')
