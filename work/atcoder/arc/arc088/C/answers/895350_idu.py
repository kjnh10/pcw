'''input
3 20
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
x,y = map_input()
ans = 0
while x <= y:
	x *= 2
	ans += 1
print(ans)	