/*This program implements the merge sort algorithm which is a stable sort but not in-place */

function merge(arr,start,mid,end)
{
    arr1 = [];
    arr2 = [];

    var i = start;
    var j = mid+1;

    while(i<=mid)
    {
        arr1.push(arr[i++]);
    }
    while(j<=end)
    {
        arr2.push(arr[j++]);
    }

    i = j = 0;
    var k = start;
    while((i<arr1.length)&&(j<arr2.length))
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while(i<arr1.length)
    {
        arr[k++] = arr1[i++];
    }
    while(j<arr2.length)
    {
        arr[k++] = arr2[j++];
    }
}

function sort(arr,start,end)
{
    if(start<end)
    {
        var mid = Math.floor((start+end)/2);
        sort(arr,start,mid);
        sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

var arr = [];
for(var i=100,j=0;i>0;i--)
{
    arr[j++]=i;
}
console.log(arr);

sort(arr,0,arr.length-1);
console.log(arr);