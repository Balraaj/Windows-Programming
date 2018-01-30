def InsertionSort(arr):
    for i in range(1,len(arr)):
        for j in range(i,0,-1):
            if(arr[j]<arr[j-1]):
                temp=arr[j]
                arr[j]=arr[j-1]
                arr[j-1]=temp
    return



mylist=[]
j=100000
for i in range(10000):
    mylist.append(j)
    j-=1


InsertionSort(mylist)
print("\nSorted list : ")
print(mylist)