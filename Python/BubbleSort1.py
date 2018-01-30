def bubblesort(arr):
    for i in range(len(arr)-1):
        for j in range(len(arr)-i-1):
            if(arr[j]>arr[j+1]):
                temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp


mylist=[123,1,234,56,2,3,67,8,9,1010]
print(mylist)
bubblesort(mylist)
print(mylist)