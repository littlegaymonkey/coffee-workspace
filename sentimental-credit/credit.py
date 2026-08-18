while True:
    s = input("Cards number is: ")
    if s.isnumeric():
        if len(s) < 17:
            break

l = len(s)

# Вспомогательные суммы
sum = 0
sum2 = 0

# Сумма четных чисел умнож на два
for i in range(l - 2, -1, -2):
    sum = (
        sum
        + (int(s[i]) * 2) % 10
        + ((((int(s[i]) * 2) % 100) - (int(s[i]) * 2) % 10) / 10)
    )

# Сумма нечетных чисел
for k in range(l - 1, -1, -2):
    sum2 += int(s[k])

# Проверочная сумм (модуль должен быть 0)
sum3 = sum2 + sum

if sum3 % 10 == 0:
    if l == 15 and ((int(s[0] + s[1])) == 34 or (int(s[0] + s[1])) == 37):
        print("AMEX")
    elif l == 16 and ((int(s[0] + s[1])) < 56 and (int(s[0] + s[1])) > 50):
        print("MASTERCARD")    
    elif (l == 13 or l == 16) and s[0] == '4':
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
