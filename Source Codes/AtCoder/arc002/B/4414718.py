from datetime import date,timedelta
y,m,d=map(int,input().split("/"))#???????
dt=date(year=y,month=m,day=d)#?????date?????
while dt.year/dt.month%dt.day:#??????????????
  dt+=timedelta(days=1)#????????????????????????
  #print(dt)
print(dt.strftime("%Y/%m/%d"))