n = int(input())
data = list(map(int, input().split(" ")))
data.insert(0,0)
data.append(0)
allans = 0
for i in range(0, len(data)-1):
    allans += abs(data[i+1]-data[i])
for i in range(1, len(data)-1):
    temp=abs(data[i]-data[i-1])
    temp2=abs(data[i+1]-data[i])
    temp3=abs(data[i+1]-data[i-1])
    print(allans-temp-temp2+temp3)