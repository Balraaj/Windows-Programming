var arr = [123,45,0,-987,876,1234,1,2,3,56];

function SelectionSort(arr)
{
    for(var i=0;i<arr.length-1;i++)
    {
        var index = i;
        for(var j=i+1;j<arr.length;j++)
        {
            if(arr[j]<arr[index])
            {
                index = j;
            }
        }

        var temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

var result = SelectionSort(arr);
console.log("This is selection sort procedure");
console.log(result);