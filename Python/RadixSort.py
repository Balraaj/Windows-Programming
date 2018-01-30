def sort(arr):
    m = 0
    exp = 1
    c = []
    for i in range(len(arr)):
        c.append(0)
        if(arr[i]>m):
            m = arr[i]

    while(m//exp>0):

        box = []
        for i in range(10):
            box.append(0)

        for i in range(len(arr)):
            box[(arr[i]//exp)%10]+=1

        for i in range(1,10):
            box[i] = box[i]+box[i-1]

        for i in range(len(arr)-1,-1,-1):
             n = arr[i]//exp%10
             box[n]-=1
             c[box[n]]=arr[i]

        for i in range(len(arr)):
            arr[i]=c[i]

        exp*=10

    return arr

arr=[1,23,567,4,0,1,2,3,0,5,4,0,0]
print("Soted array is : ")

temp = sort(arr)
print(temp)