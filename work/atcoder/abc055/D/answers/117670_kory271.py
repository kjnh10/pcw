# coding: utf-8
def getLnInputs():
    return input().split()


def getLnIntInputs():
    return list(map(int, getLnInputs()))


def is_next_sheep(isCurrentSheep, response, isPreviousSheep):
    isNextSame = not (isCurrentSheep ^ response)
    return not (isNextSame ^ isPreviousSheep)


def resolve_hypothesis(firstIsSheep, lastIsSheep, responseArray):
    res_str = "S" if firstIsSheep else "W"

    isCurrentSheep = firstIsSheep
    isPreviousSheep = lastIsSheep

    for i in range(len(responseArray) - 1):
        isNextSheep = is_next_sheep(isCurrentSheep, responseArray[i], isPreviousSheep)
        res_str += "S" if isNextSheep else "W"
        isCurrentSheep, isPreviousSheep = isNextSheep, isCurrentSheep

    if isCurrentSheep != lastIsSheep or is_next_sheep(isCurrentSheep, responseArray[-1], isPreviousSheep) != firstIsSheep:
        return -1

    return res_str


def main():
    input()
    s = input()

    responseArray = list(map(lambda c: c == "o", list(s)))

    for i in range(2):
        for j in range(2):
            firstIsSheep = bool(i)
            lastIsSheep = bool(j)
            res = resolve_hypothesis(firstIsSheep, lastIsSheep, responseArray)

            if res == -1:
                continue

            print(res)
            return

    print(-1)
    return


main()
