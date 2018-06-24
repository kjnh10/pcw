# -*- coding: utf-8 -*-
from datetime import datetime, timedelta

def main():
    s = input()
    d = datetime.strptime(s, '%Y/%m/%d')

    while True:
        # 割り切れる日付なら抜ける
        if d.year % (d.month * d.day) == 0:
            break
        d += timedelta(days=1)

    # print the date
    out = d.strftime('%Y/%m/%d')
    print(out)

if __name__ == '__main__':
    main()
