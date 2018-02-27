result = 0
result2 = 0

def adder(num):
    global result
    result += num
    return result

print(adder(3))
print(adder(4))

def adder2(num):
    global result2
    result2 += num
    return result2

print(adder2(3))
print(adder2(7))
