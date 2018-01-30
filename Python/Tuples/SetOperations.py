"""This program shows some basic operations of set data type"""

set1=set()
set2=set()

set1.update({1,2,3,4,5,6})
for i in range(50):
    set1.add(i)

for i in range(40,50):
    set2.add(i)

print(set1)
print(set2)

print(set1.issubset(set2))
print(set2.issubset(set1))

set3=set1.difference(set2)
set4=set2.difference(set1)

print(set3)
print(set4)

print("Union is : "+str(set1.union(set2)))
print("Intersection is : "+str(set1.intersection(set2)))
print("set1 is superset of set2 : "+str(set1.issuperset(set2)))