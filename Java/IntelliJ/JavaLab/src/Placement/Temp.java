package Placement;


public class Temp
{
    private static int LIS(int[] arr)
    {
        boolean[] flag = new boolean[arr.length];
        int lenFirst = 0;
        int lenSecond = 1;
        int[] sub1 = new int[arr.length];
        int[] sub2 = new int[arr.length];
        int k;

        for(int i=0;i+lenFirst<=arr.length;i++)
        {
            k=0;
            if(!flag[i])
            {
                sub2[k++]=i;
                for(int j = i + 1; j < arr.length; j++)
                {
                    if(arr[j]>arr[i])
                    {
                        flag[j]=true;
                        lenSecond++;
                        sub2[k++]=j;
                    }
                }
            }

            if(lenSecond>lenFirst)
            {
                lenFirst = lenSecond;
                for(int m=0;m<lenFirst;m++)
                {
                    sub1[m]=sub2[m];
                }
            }
            lenSecond = 1;
        }

        for(int i=0;i<lenFirst;i++)
        {
            System.out.print(arr[sub1[i]]+" ");
        }
        return lenFirst;
    }


    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,1,1,1,5,6,7,8,9,1};
        System.out.print("Length of LIS is : "+LIS(arr));
    }

}
