"""This program shows the uses of tuple assignment and how more than one values can be returned"""

def myfunc(max):
    i=0
    while(i<max):
        yield i,i**2  #Yeilding two values, actually its a tuple and that is why only one object
        i+=1

    return

mylist=[]
for x,y in myfunc(10):
    mylist.append((x,y)) #creating a list using tuples returned by myfunc

print(mylist)