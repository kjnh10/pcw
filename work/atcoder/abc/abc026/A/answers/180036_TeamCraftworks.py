def main():
    A = int(input())
    v = A//2
    print(max(v*(A-v),(v+1)*(A-(v+1)),(v-1)*(A-(v-1))))

if __name__ == "__main__":
    main()