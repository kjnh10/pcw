
def main():
    A,B = map(int,input().split())
    print(max((A+1)*B,A*(B+1)))

if __name__ == "__main__":
    main()
