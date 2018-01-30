"""This program demonstrates a simple set comprehension"""
myset=set()

for i in range(20):
    myset.add(i)

myset1={i//2 for i in myset if i%2==0}
print(myset)
print(myset1)