def main():
    a=input().split("+")
    w=0
    for s in a:
        if s.find("0")==-1:
            w=w+1
    print(w)

if __name__ == "__main__":
    main()
