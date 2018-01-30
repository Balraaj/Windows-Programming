def SelectionSort(arr):
    for i in range(len(arr)-1):
        key=arr[i]
        index=i
        for j in range(i+1,len(arr)):
            if (arr[j]<key):
                key=arr[j]
                index=j
        temp=arr[i]
        arr[i]=arr[index]
        arr[index]=temp
    return


mylist=[123,23,4,1,23,34]
SelectionSort(mylist)
print(mylist)