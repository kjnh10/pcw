def solve():
    N = int(input())
    tl = tuple(map(int, input().split()))
    vl = tuple(map(int, input().split()))
    vlim = [0]*N
    prev = 0
    for i, (t, v) in enumerate(zip(tl[:0:-1], vl[:0:-1]), start=1):
        prev = min(v, t+prev)
        vlim[N-i-1] = prev

    rem_time = sum(tl)
    dist = 0
    speed = 0
    for i, (t, v) in enumerate(zip(tl, vl)):
        lim = vlim[i]
        for j in range(t*2, 0, -1):
            #print(j, speed, dist)
            j /= 2
            if speed - j >= lim:
                dist += (speed*2-1)/4
                speed -= 0.5
            elif speed < v:
                dist += (speed*2+1)/4
                speed += 0.5
            elif speed == v:
                dist += speed/2
            else:
                raise Exception("hogeeeee")

    print(dist)



if __name__ == "__main__":
    solve()