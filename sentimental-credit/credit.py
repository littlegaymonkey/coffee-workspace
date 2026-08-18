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
for i in range(l - 1, -1, -2):
    sum = (
        sum
        + (int(s[i]) * 2) % 10
        + ((((int(s[i]) * 2) % 100) - (int(s[i]) * 2) % 10) / 10)
    )

# Сумма нечетных чисел
for k in range(l - 2, -1, -2):
    sum2 += int(s[k])

# Проверочная сумм (модуль должен быть 0)
sum3 = sum2 + sum
print(sum)
print(sum2)
print(sum3)
