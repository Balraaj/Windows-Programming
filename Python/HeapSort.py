def swap(arr,i,j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def heapify(arr,i,heapsize):
    max = 0
    l = i*2+1
    r = i*2+2

    if((l<heapsize)and(arr[l]>arr[i])):
        max = l
    else:
        max = i

    if((r<heapsize)and(arr[r]>arr[max])):
        max = r

    swap(arr,i,max)

    if(i!=max):
        heapify(arr,max,heapsize)


def sort(arr):
    heapsize = len(arr)

    top = (heapsize//2)-1

    for i in range(top,-1,-1):
        heapify(arr,i,heapsize)

    for i in range(heapsize-1,0,-1):
        swap(arr,0,i)
        heapsize -= 1
        heapify(arr,0,heapsize)


arr = [123,12,45,1,2,78978,123,-1,-12312,234,88888]
sort(arr)

print(arr)
