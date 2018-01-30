def swap(arr,i,j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def heapify(arr,i):
    heapsize = len(arr)

    l = i*2+1
    r = i*2+2
    max = 0

    if((l<heapsize)and(arr[l]>arr[i])):
        max = l
    else:
        max = i

    if((r<heapsize)and(arr[r]>arr[max])):
        max = r

    if(i!=max):
        swap(arr,i,max)
        heapify(arr,max)


arr = [1,4,123,678,3,12345,-1,-123,999]

top = (len(arr)//2)-1

for i in range(top,-1,-1):
    heapify(arr,i)

print(arr)