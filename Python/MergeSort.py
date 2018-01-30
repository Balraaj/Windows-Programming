def Merge(a,b,arr):
    k=0
    i=0
    j=0

    while((i<len(a))and(j<len(b))):
        if(a[i]<b[j]):
            arr[k]=a[i]
            i+=1
            k+=1
        else:
            arr[k]=b[j]
            j+=1
            k+=1



    if(i<len(a)):
        for z in range(i,len(a)):
            arr[k]=a[z]
            k+=1

    else:
        for z in range(j,len(b)):
            arr[k]=b[z]
            k+=1

    return


def Mergesort(arr):
    if(len(arr)==1):
        return
    else:
        m=len(arr)//2
        n=len(arr)-m

        a=[]
        b=[]
        k=0
        for i in range(0,m):
            a.append(arr[i])
            k+=1

        for i in range(k, len(arr)):
            b.append(arr[i])

    Mergesort(a)
    Mergesort(b)

    Merge(a,b,arr)

    return



mylist=[]
j=100000
for i in range(100000):
    mylist.append(j)
    j-=1

Mergesort(mylist)

print(mylist)