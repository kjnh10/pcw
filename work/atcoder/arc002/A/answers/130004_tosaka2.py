y=int(input())
print("NO"if y%400!=0 and (y%100==0 or y%4)else"YES")