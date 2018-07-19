from sys import stdin, stdout
def IL():return list(map(int, stdin.readline().split()))

def main():
    N,Z,W = IL()
    a = IL()
    if len(a)>1:
        p=abs(a[-2] - a[-1])
        q=abs(a[-1] - W)
        print(max(p,q))
    else:
        print(abs(a[0]-W))
        
if __name__ == "__main__": main()