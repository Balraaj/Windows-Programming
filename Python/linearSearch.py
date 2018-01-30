"""This program is an introduction to python programming it implements linear search"""
def search(x,arr):

    value=False
    for no in arr:
        if(no==x):
            value=True
            break

    if x:
        print("Value is found")
    else:
        print("Value not found")

    return

Mylist =[]

for i in range(0,10,3):
    x=int(input("Enter a no :  "))
    Mylist.append(x)


number=int(input("Enter value to search : "))
search(number,Mylist)





