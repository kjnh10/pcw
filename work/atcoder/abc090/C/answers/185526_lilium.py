



def main():
    temp=input()
    temp=list(map(int,list(temp.split(" "))))    
    a=int(temp[0])
    b=int(temp[1])
    c=a*b
    count=c-2*a-2*b+4
    if count<0:
        count*=-1
    print(count)


if __name__ == '__main__':
    main()
