def fibo(n):
    if n >= 2:
        return fibo(n - 1) + fibo(n - 2)
    else:
        return n


a = int(input("\n"))
fiboplus = 0
print("숫자를 입력하시오: ", end="")
for i in range(1, a+1):
    print(fibo(i), end=" ")