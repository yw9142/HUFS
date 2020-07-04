# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

movies = ["Dark Knight", "Harry Porter", "Parasite", "Matrix", "La La Land"]
movie_price = 12000

print()
print("===========영화 목록===========")
for i in movies:
    print(i)
print("==============================")

choice = input("예매하실 영화를 선택해주세요: ")

while choice not in movies:
    print("예매할 수 없는 영화입니다")
    choice = input("예매하실 영화를 선택해주세요: ")
print(f"{choice}를 선택하셨습니다")

check = False
while (not (check)):

    people = int(input("관람 인원 수를 입력해주세요: "))
    if people <= 0:
        print("관람 인원 수는 양수만 가능합니다")
    else:
        print(f"관람할 인원 수는 {people}명입니다")
        break

coupon_dic = {'WELCOME': 2000, 'VALENTINE': 3000, 'CHRISTMAS': 4000, 'INDEPENDENCE': 5000}
process = True

usage = input("할인권을 사용하시려면 y, 금액 확인으로 넘어가시려면 n을 입력해주세요: ")

while process:
    if usage == 'y':
        coupon = input("쿠폰 번호를 입력해주세요: ")
        if coupon in coupon_dic:
            sale = coupon_dic.get(coupon)
            print("%d원 할인됩니다" % sale)
            process = False
        else:
            print('존재하지 않는 할인권입니다')
            usage = input("할인권을 다시 입력하려면 y, 아니면 n을 입력해주세요: ")
    elif usage == 'n':
        sale = 0
        print('할인권을 사용하지 않았습니다')
        process = False
    else:
        usage = input('잘못된 입력입니다. 다시 입력해주세요: ')

origin_price = movie_price * people
sale_price = sale * people
total_price = origin_price - sale_price

print("")
print("<예매 상세 내역>")
print("==============================")
print(f"영화 제목: {choice}")
print(f"관람 인원: {people}명")
print(f"합산 금액: {origin_price}원")
print(f"할인 금액: {sale_price}원")
print("------------------------------")
print(f"실 결제액: {total_price}원")
print("==============================")
