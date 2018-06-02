function partition(arr,start,end)
{
    var pivot = arr[end];
    var index = start;
    for(var i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            var temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index++;
        }
    }

    arr[end] = arr[index];
    arr[index] = pivot;
    return index;
}

function partitionHoare(arr,start,end)
{
    var i = start-1;
    var j = end+1;
    var pivot = arr[start];
    while(true)
    {
        do
        {
            i++;
        }while(arr[i]<pivot)

        do
        {
            j--;
        }while(arr[j]>pivot)

        if(i<j)
        {
            var temp = arr[i];
            arr[i] = arr[j];
            arr[j] =temp;
        }
        else
        {
            return j;
        }
    }
}
function sort(arr, start, end)
{
    if(start<end)
    {
        var pivot = partitionHoare(arr,start,end);
        sort(arr,start,pivot);
        sort(arr,pivot+1,end);
    }
}

var arr = [123,1,-123,34,-68,0,1234,-1,8,9,-1,-1,34,-68];
sort(arr,0,arr.length-1);
console.log(arr);