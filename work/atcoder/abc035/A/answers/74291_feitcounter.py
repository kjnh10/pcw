def getAspect(W, H):
    if W/H < 1.5:
        return "4:3"
    else:
        return "16:9"

W, H = list(map(int, input().split()))
print(getAspect(W, H))
