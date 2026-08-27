class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Negative capasity")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        self._size += n
        if self._size > self._capacity:
            raise ValueError("TO MANY COKIES AHHHWWWW")

    def withdraw(self, n):
        self._size = self._size - n
        if self._size < 1:
            raise ValueError("NEGATIVE COOKIES ARHHGG")

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


def main():
    jar = Jar(20)
    print("Capacity of Jar is ", end="")
    print(str(jar.capacity))

    print("Eat coockie untill you full. Once you done: press Ctrl + d")
    while True:
        try:
            x = input("How many cockies shall we put? ")
            if x.isdigit():
                jar.deposit(int(x))
            print("Wow! There is some coockies! Look at them -> ", end="")
            print(str(jar))
            y = input("How many coockie shall we NOM NOM NOM? ")
            if y.isdigit():
                jar.withdraw(int(y))
            print("Yayks! There some coockie left. Look -> ", end="")
            print(str(jar))
        except EOFError:
            print("\n\n\n\nI hope you got some coockie! Bye!")
            break


main()
