import datetime
X = list(map(int,input().split('/')))
SDate=datetime.date(X[0],X[1],X[2])

while (SDate.year % (SDate.month*SDate.day)) != 0:
    SDate += datetime.timedelta(days=1)

print(str(SDate.year).zfill(4)+'/'+str(SDate.month).zfill(2)+'/'+str(SDate.day).zfill(2))