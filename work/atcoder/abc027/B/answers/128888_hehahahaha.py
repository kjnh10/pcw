sima=float(input())
ninzu=[int(i) for i in input().split(' ')]
hasi=0
total=0

for i in ninzu: total = total + i

heikin=(total/sima)

if (int(heikin)!=(heikin)):
    print(-1)
else:
    for i in range(int(sima)):
        if(ninzu[i]==(heikin)):
            continue
        else:
            hasi=hasi+1
            ninzu[i+1]=ninzu[i+1]+(ninzu[i]-heikin)
            ninzu[i]=heikin
    print(hasi)