def list_map(func, xs: list) -> list: return list(map(func, xs))
def input_str()      -> str:   return input().strip()
def input_int()      -> int:   return int(input().strip())
def input_list()     -> [str]: return input().strip().split()
def input_int_list() -> [int]: return list_map(int, input_list())

def main():
    w, h = input_int_list()
    if (w / 4 * 3 == h):
        print('4:3')
    else:
        print('16:9')

if __name__ == '__main__':
    main()