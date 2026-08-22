greating = input("Greating: ")

hello = 'hello'

if hello in greating.lower():
    print('$0')
elif greating[0].lower() == 'h':
    print('$20')
else:
    print('$100')