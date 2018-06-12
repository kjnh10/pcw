n,m = list(map(int,input().split()))

X =list(map(int,input().split()))
Y = list(map(int,input().split()))


"""
3*2 * 5*2

"""
#print( (X[-1]-X[0])*(n-1) * (m-1)*(Y[-1]-Y[0]) )# %1000000007

def calc_diff(L):
    result = 0
    #n_of_diff
    for i,l in enumerate(L):
        if i==len(L)-1:
            break
            #hidari x migi
        result += (i+1)*(len(L)-i-1)* (L[i+1]-L[i])
        result = result %1000000007
        #print(result)
    return result

print(calc_diff(X) *calc_diff(Y) %1000000007 )