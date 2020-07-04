# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

fruits_dic = {"apple": 5000, "banana": 2000, "cherry": 4000, "durian": 10000, "elderberry": 3000, "fig": 8000}
print(f"apple의 가격은 {fruits_dic.get('apple')} 입니다.")
print(f"banana의 가격은 {fruits_dic.get('banana')} 입니다.")
print(f"cherry의 가격은 {fruits_dic.get('cherry')} 입니다.")
print(f"durian의 가격은 {fruits_dic.get('durian')} 입니다.")
print(f"elderberry의 가격은 {fruits_dic.get('elderberry')} 입니다.")
print(f"fig의 가격은 {fruits_dic.get('fig')} 입니다.\n")

print(f"grape는 fruits_dic의 key: ", end="")
if 'grape' in fruits_dic:
    print(f"항목에 있습니다.\n")
else:
    print(f"False\n")

fruits_dic["grape"] = 3000
print(f"insert: grape의 가격은 {fruits_dic.get('grape')} 입니다.\n")

fruits_dic["elderberry"] = 5000
print(f"update: elderberry의 가격은 {fruits_dic.get('elderberry')} 입니다.\n")

print(f"{fruits_dic.keys()}\n")

if 'apple' in fruits_dic:
    del(fruits_dic["apple"])
    print(f"delete: key 'apple'를 삭제했습니다.\n")
else:
    print(f"항목에 없습니다.\n")


print(f"{fruits_dic.items()}\n")

fruits_dic.clear()
print(fruits_dic)