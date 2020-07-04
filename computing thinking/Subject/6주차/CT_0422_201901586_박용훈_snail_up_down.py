# -*- coding: utf-8 -*-

daytime = 3
night = 2
height = 0
count = 0

while(1):
    count += 1 # 날짜 카운트
    height += daytime # 낮에 상승
    if height == 30: # 30m 올라왔으면 종료
        break
    height -= night # 아니면 2m 하락

print(f"It took {count} days")
