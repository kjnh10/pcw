
s = input()
k = int(input())

array = []
max_length = 6
if(len(s) < 5):
    max_length = len(s) + 1
for l in range(1, max_length):
    for i in range(len(s)):
        if i + l > len(s):
            continue
        array.append(s[i:i+l])
        
array = list(set(array))
array.sort()
print(array[k-1])