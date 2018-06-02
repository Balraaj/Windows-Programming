var arr = [34,21,2,6,7,89,44,0,-34];



function InsertionSort(arr)
{
    for(var i=1;i<arr.length;i++)
    {
        var value = arr[i];
        var j = i-1;
        while((j>=0)&&(arr[j]>value))
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=value;
    }
    return arr;
}

var myarr = InsertionSort(arr);
console.log(myarr);