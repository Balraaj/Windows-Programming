def BubbleSort(arr):
    for i in range(0,len(arr)-1):
        flag = False
        for j in range(0,len(arr)-1-i):
            if (arr[j]>arr[j+1]):
                flag=True # list is not sorted
                temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp

        if (not flag): # list is sorted because no swap was made
            break
    return


z=[]
for i in range(0,10000):
    z.append(i)

print(z)
BubbleSort(z)
print(z)
