import numpy as np
import bisect

X , Y = input().split()
X = int(X)
Y = int(Y)

rst = (X - Y) * 100 + 1900 * Y
rst = 2**Y * rst
print(rst)