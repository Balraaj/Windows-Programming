/* This program implements the heapsort algorithm. heapsort is an in-place sort and its not stable.
   It has worst case time complexity of O(NlgN) */


/*This function constructs a max heap rooted at node index, it starts with the assumption that trees rooted at
   the left-child and the right-child of index are max heaps */
function maxHeapify(arr,heapLength,index)
{
    var maximum = index;
    var leftChild = index*2+1;
    var rightChild = index*2+2;

    if((leftChild<heapLength)&&(arr[leftChild]>arr[index]))
    {
        maximum = leftChild;
    }

    if((rightChild<heapLength)&&(arr[rightChild]>arr[maximum]))
    {
        maximum = rightChild;
    }

    if(maximum!=index)
    {
        var temp = arr[maximum];
        arr[maximum] = arr[index];
        arr[index] = temp;
        maxHeapify(arr,heapLength,maximum);
    }
}

function buildMaxHeap(arr)
{
    var length = arr.length;
    var heapLength = arr.length;
    var startIndex = Math.floor((length-2)/2);

    while(startIndex>=0)
    {
        maxHeapify(arr,heapLength,startIndex--);
    }
}

function heapSort(arr)
{
    buildMaxHeap(arr);

    var startIndex = arr.length-1;
    var heapLength = arr.length;
    while(startIndex>0)
    {
        var temp = arr[startIndex];
        arr[startIndex] = arr[0];
        arr[0] = temp;
        maxHeapify(arr,--heapLength,0);
        startIndex--;
    }
}


var arr = [];

for(var i=100000,j=0;i>0;i--)
{
    arr[j++]=i;

}

heapSort(arr);
console.log("Sorted array : "+arr);