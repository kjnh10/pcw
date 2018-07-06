import re
X = input()
if re.match("^(ch|o|k|u)*$", X):
    print("YES")
else:
    print("NO")
