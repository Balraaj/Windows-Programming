function sort(arr,M)
{
    var A = [];
    for(var i=0;i<M;i++)
    {
        A[i]=0;
    }

    for(var i=0;i<arr.length;i++)
    {
        A[arr[i]]++;
    }

    for(var i=1;i<M;i++)
    {
        A[i]=A[i-1]+A[i];
    }

    var C = [];

    for(var i=arr.length-1;i>=0;i--)
    {
        C[A[arr[i]]-1]=arr[i];
        A[arr[i]]--;
    }

    return C;

}

var arr = [12,23,45,11,2,2,5,23];
var arr1 = sort(arr,46);
console.log(arr1);