def selectionsort(arr):
    for i in range(len(arr)-1):
        index=i
        for j in range(i+1,len(arr)):
            if(arr[index]>arr[j]):
               index=j
        temp=arr[index]
        arr[index]=arr[i]
        arr[i]=temp

mylist=[123,23,1,4,34,2,3,89]
print(mylist)

selectionsort(mylist)
print(mylist)