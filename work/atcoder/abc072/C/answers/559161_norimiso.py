temp = input().split(" ")
n = int(temp[0])
inp = input().split(" ")
nums = [0 for a in range(100003)]
for a in range(n):
    nums[int(inp[a])+1]+=1
    nums[int(inp[a])+2]+=1
    nums[int(inp[a])]+=1
print(max(nums))
 