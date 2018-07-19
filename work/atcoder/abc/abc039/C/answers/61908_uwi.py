import sys


stdin = sys.stdin

s = stdin.readline().strip()
wb = "WBWBWWBWBWBW" * 5
ind = wb.find(s)
print(["Do","","Re","","Mi","Fa","","So","","La","","Si"][ind])