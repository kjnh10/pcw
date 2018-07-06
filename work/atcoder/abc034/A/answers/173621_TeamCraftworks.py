def main():
    x,y = map(int,input().split())
    if x < y:
        print("Better")
    else:
        print("Worse")

if __name__ == "__main__":
    main()