# -*- coding:utf-8 -*-
import re

s = input()
f = True
while(f):
    if(re.search('dreameraser', s)):
        s = re.sub('dreameraser', '', s)
    elif(re.search('dreamerase', s)):
        s = re.sub('dreamerase', '', s)
    elif(re.search('dreamer', s)):
        s = re.sub('dreamer', '', s)
    elif(re.search('dream', s)):
        s = re.sub('dream', '', s)
    elif(re.search('eraser', s)):
        s = re.sub('eraser', '', s)
    elif(re.search('erase', s)):
        s = re.sub('erase', '', s)
    else:
        f = False
print("NO" if len(s) > 0 else "YES")
