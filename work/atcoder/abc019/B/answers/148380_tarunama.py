s = input()


def main(s):
    ret = ''
    lst = []
    count = 1

    for i, c in enumerate(s):
        if len(s) == i + 1:
            insert = c + str(count)
            lst.append(insert)
        elif c != s[i + 1]:
            insert = c + str(count)
            lst.append(insert)
            count = 1
        else:
            count += 1

    return ret.join(lst)

ans = main(s)
print(ans)