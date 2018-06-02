function rSort(arr)
{
    var m=0;
    var exp=1;

    for(var i=0;i<arr.length;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    while(Math.floor(m/exp)>0)
    {
        arr = cSort(arr,exp);
        exp*=10;
    }
    return arr;
}

function cSort(arr,radix)
{
    var A = [];
    for(var i=0;i<10;i++)
    {
        A[i]=0;
    }

    for(var i=0;i<arr.length;i++)
    {
        var v = (Math.floor(arr[i]/radix))%10;
        A[v]++;
    }

    for(var i=1;i<10;i++)
    {
        A[i]=A[i]+A[i-1];
    }

    var C = [];
    for(var i=arr.length-1;i>=0;i--)
    {
        v = Math.floor(arr[i]/radix)%10;
        C[A[v]-1] = arr[i];
        A[v]--;
    }

    return C;
}

var arr = [123,23,1,2,4,1234,89];
arr = rSort(arr);
console.log(arr);