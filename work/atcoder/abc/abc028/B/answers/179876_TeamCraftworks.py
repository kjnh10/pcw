
def main():
    s = input()
    print(*[s.count(c) for c in "ABCDEF"])

if __name__ == "__main__":
    main()
