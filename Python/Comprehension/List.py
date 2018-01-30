"""This program demonstrates how list comprehension works"""

mylist=[]
for i in range(20):
    mylist.append(i)

mylist1=[i//2 for i in mylist if i%2==0]

print(mylist)
print(mylist1)