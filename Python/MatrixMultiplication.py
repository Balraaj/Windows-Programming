#This program multiply two square matrix
def Multiply(a,b,c):
    for i in range(len(a)):
        for j in range(len(a[0])):
            sum=0
            for k in range(len(a)):
                sum+=a[i][k]*b[k][j]
            c[i][j]=sum

    return


mylist=[]
mylist1=[]
mylist2=[]
ROWS=int(input("How many rows you want : "))
COLUMNS=int(input("How many columns you want : "))

for i in range(ROWS):
    mylist.append([])
    mylist1.append([])
    mylist2.append([])
print("Enter values of first matrix")

for i in range(ROWS):
    for j in range(COLUMNS):
        mylist[i].append(int(input("Enter a no : ")))

print("Enter values of second matrix")
for i in range(ROWS):
    for j in range(COLUMNS):
        mylist1[i].append(int(input("Enter a no : ")))
        mylist2[i].append(0)


Multiply(mylist,mylist1,mylist2)

print("Contents of first matrix")
for i in range(ROWS):
    for j in range(COLUMNS):
        print("   "+str(mylist[i][j]),end='')
    print()


print("Contents of second matrix")
for i in range(ROWS):
    for j in range(COLUMNS):
        print("   "+str(mylist1[i][j]),end='')
    print()


print("Contents of Result matrix")
for i in range(ROWS):
    for j in range(COLUMNS):
        print("   "+str(mylist2[i][j]),end='')
    print()
