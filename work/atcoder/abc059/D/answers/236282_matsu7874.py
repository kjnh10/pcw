
memo = {(0,1):False, (1, 1): False}
def solve(p):
    x,y = p
    if x > y:
        x,y = y,x
    if (x, y) in memo:
        return memo[(x,y)]
    if x < 2 and y < 2:
        return False
    hand = []
    for i in range(2, x+1, 2):
        hand.append((x-i, y+i//2))
    for i in range(2, y+1, 2):
        hand.append((x+i//2, y-i))
    if all(map(solve, hand)):
        memo[(x,y)] = False
    else:
        memo[(x,y)] = True    
    return memo[(x,y)]

def solve2(p):
    x,y = p
    if x > y:
        x,y = y,x
    return not (-1 <= y-x <= 1)



if __name__ == '__main__':
    X,Y = map(int, input().split())
    # print('Alice' if solve((X, Y)) else 'Brown')
    print('Alice' if solve2((X, Y)) else 'Brown')
    # N = 100
    # a = [['Alice' if solve((i, j)) else 'Brown' for j in range(N)] for i in range(N)]
    # for i in range(N):
    #     print('\t'.join(a[i]))
    # for i in range(N):
    #     for j in range(N):
    #         if solve((i, j)) != solve2((i, j)):
    #             print(i,j)
            # print(i,j,'Alice' if solve((i, j)) else 'Brown')
    