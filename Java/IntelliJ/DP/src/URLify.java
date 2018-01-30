/**
 * Created by Balraj on 27-Jan-18.
 */
public class URLify
{
    /*private static void changeStringh(char[] arr,int length)
    {
        for(int i=0;i<length;i++)
        {
            if(arr[i]==' ')
            {
             // this is slower as we have to perform shift every time we find a space

                for(int j=length-1;j>i;j--)
                {
                    arr[j+2]=arr[j];
                }

                arr[i]='%';
                arr[i+1]='2';
                arr[i+2]='0';
            }
        }
    }*/

    private static void changeString(char[] arr,int length)
    {
        int spaceCount=0;
        for(int i=0;i<length;i++)
        {
            if(arr[i]==' ')
            {
                spaceCount++;
            }
        }

        int index=length+spaceCount*2;
        arr[index]='\0';

        for(int i=length-1;i>=0;i--)
        {
            if(arr[i]==' ')
            {
                arr[index-1]='0';
                arr[index-2]='2';
                arr[index-3]='%';
                index=index-3;
            }
            else
            {
                arr[index-1]=arr[i];
                index=index-1;
            }
        }
    }

    public static void main(String[] args)
    {
        char[] arr="hello he is we            ".toCharArray();
        System.out.println("Length of array before call : "+arr.length);
        changeString(arr,14);
        System.out.println("Length of array after call  : "+arr.length);

        for(char c:arr)
        {
            System.out.print(c);
        }
    }
}
