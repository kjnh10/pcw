t = input()
s = list(map(int,list(t)))

if s[0] + s[1] + s[2] + s[3] == 7:
    print(t[0]+"+"+t[1]+"+"+t[2]+"+"+t[3]+"=7")
elif s[0] + s[1] + s[2] - s[3] == 7:
    print(t[0]+"+"+t[1]+"+"+t[2]+"-"+t[3]+"=7")
elif s[0] + s[1] - s[2] + s[3] == 7:
    print(t[0]+"+"+t[1]+"-"+t[2]+"+"+t[3]+"=7")
elif s[0] + s[1] - s[2] - s[3] == 7:
    print(t[0]+"+"+t[1]+"-"+t[2]+"-"+t[3]+"=7")
elif s[0] - s[1] + s[2] + s[3] == 7:
    print(t[0]+"-"+t[1]+"+"+t[2]+"+"+t[3]+"=7")
elif s[0] - s[1] + s[2] - s[3] == 7:
    print(t[0]+"-"+t[1]+"+"+t[2]+"-"+t[3]+"=7")
elif s[0] - s[1] - s[2] + s[3] == 7:
    print(t[0]+"-"+t[1]+"-"+t[2]+"+"+t[3]+"=7")
elif s[0] - s[1] - s[2] - s[3] == 7: 
    print(t[0]+"-"+t[1]+"-"+t[2]+"-"+t[3]+"=7")