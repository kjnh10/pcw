N = int(input())

data = [list(map(int,input().split())) for _ in range(N)]

def nibun_float(func , min_ ,max_, seido):
    left = min_
    right= max_
    for _ in range(seido):
        #assert left <=right
        mid = (left+right) / 2
        #print(mid,left,right)
        tmp = func(mid)
        if tmp:
            right = mid
        else:
            left = mid
    return left

xc = [ (x_,c_) for x_,y_,c_ in data]

def calc(X):
    max_ = -100000000000000000
    min_ =  100000000000000000
    for x,c in xc:
       max_ = max(max_ ,(x-X)*c) 
       min_ = min(min_ ,(x-X)*c)
    return max(max_ ,-min_)

def f(X):
    max_ = -1
    min_ =  1
    for x,c in xc:
       max_ = max(max_ ,(x-X)*c) 
       min_ = min(min_ ,(x-X)*c)
    #print(min_,max_)
    if min_ > 0:return False
    if max_ < 0: return True
    return max_ +min_ <0

resX=nibun_float(f,-100000,100000,300)
x_jikan= calc(resX)

xc = [ (y_,c_) for x_,y_,c_ in data]
resY=nibun_float(f,-100000,100000,300)
y_jikan= calc(resY)
#print(resX,resY)
print(max(x_jikan,y_jikan))
