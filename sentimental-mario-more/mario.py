while True:
    try:
        n = int(input("Height "))
        if n > 0 and n < 9:
            break
    except ValueError:
        pass
counter1 = n - 1
counter2 = 1
for i in range(n):
    for g in range(counter1):
        print(" ", end="")
    for j in range(counter2):
        print("#", end="")
    print("  ", end="")
    for k in range(counter2):
        print("#", end="")
    print()
    counter1 -= 1
    counter2 += 1
