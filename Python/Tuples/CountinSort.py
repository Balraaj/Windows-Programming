def sort(arr,k):
    c=[]
    for i in range(k+1):
        c.append(0)

    for i in range(len(arr)):
        c[arr[i]]=c[arr[i]]+1

    for i in range(1,k+1):
        c[i]=c[i]+c[i-1]

    b=[]

    for i in range(len(arr)):
        b.append(0)

    for i in range(len(arr)):
        b[c[arr[i]]-1]=arr[i]
        c[arr[i]]=c[arr[i]]-1

    return b


arr = [1,2,0,6,2,0,12,23,20,21,9992392]
z = sort(arr,9992392)
print("Original list : ")
print(arr)
print("\nSorted list : ");

print(z)