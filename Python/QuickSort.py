def Swap(arr,a,b):
    temp=arr[a]
    arr[a]=arr[b]
    arr[b]=temp
    return


def Part(arr,start,end):
    pivot=arr[end]
    pindex=start

    for i in range(start,end):
        if(arr[i]<pivot):
            Swap(arr,i,pindex)
            pindex+=1


    temp=arr[pindex]
    arr[pindex]=arr[end]
    arr[end]=temp

    return pindex


def QuickSort(arr,start,end):
    if(start<end):
        pindex=Part(arr,start,end)
        if(pindex!=end):
            QuickSort(arr,start,pindex-1)
            QuickSort(arr,pindex+1,end)


    return


arr=(123,1,3456,2,3123,34,44,111)
L=list(arr)

QuickSort(L,0,7)
print(L)
