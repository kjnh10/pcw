tmp = "".join(input().split())
x = int(pow(int(tmp), 0.5))
print(["No", "Yes"][x*x == int(tmp)])
