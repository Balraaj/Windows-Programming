arr=[]
for i in range(4):
    output=str(input("Enter a name : "))
    arr.append(output)

print(arr)

def part(arr,start,end):
    pindex=start
    value=arr[end]

def lex_sort(arr,start,end):
    if (start<end):
        pindex=part(arr)
        lex_sort(arr,start,pindex-1)
        lex_sort(arr,pindex+1,end)
    return