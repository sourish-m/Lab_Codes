import math
principal=10000
rate=3
time=4
amount=principal*math.pow((1+rate/100),time)
print("Compound Interest is",amount-principal)
