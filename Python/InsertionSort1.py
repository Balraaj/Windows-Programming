def InsertionSort(arr):
    for i in range(1,len(arr)):
        key=arr[i]
        j=i-1
        while((j>=0)and(key<arr[j])):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
    return


mylist=[10,2,14,1,456,1,13,45,8,9,4]
InsertionSort(mylist)
print(mylist)