// This program implements quick sort on a singly linked list

package DataStructure;

public class LinkedListSingle
{
    // class for nodes of linked list

    private class node
    {
        int value = 0;
        node next = null;
    }

    private node start = null;

    public LinkedListSingle()
    {
        node temp = new node();
        start = temp;
    }

    //creates a new node with value = "value" and returns the reference to it

    node createnode(int value)
    {
        node temp = new node();
        temp.value = value;
        return temp;
    }

    //inserts a new node at the end of linked list

    void insert(int value)
    {
        start.value++;
        if(start.next==null)
        {
            start.next = createnode(value);
        }
        else
        {
            node run = start.next;
            while(run.next!=null)
            {
                run = run.next;
            }

            run.next = createnode(value);
        }
    }

    //inserts a new node after the lastlink

    void insert(int value,node lastlink)
    {
        start.value++;
        node temp = lastlink.next;
        lastlink.next = createnode(value);
        lastlink.next.next=temp;
    }

    //removes link from linked list

    void delete(node link)
    {
        start.value--;

        if(start.next==link)
        {
            start.next = link.next;
        }

        else
        {
            node run = start.next;
            while(run.next!=link)
            {
                run = run.next;
            }

            run.next = link.next;
        }
    }

    //sorting procedures

    void qsort()
    {
        node run = start.next;
        while(run.next!=null)
        {
            run = run.next;
        }
        sort(start.next,run);
    }

    private static int count = 0;

    //main sorting procedure

    void sort(node start,node end)
    {
        count++;
        System.out.print("\ncall : "+count);
        if((start==end)||(start==null)||(end==null))
        {
            return;
        }
        else
        {
            node[] arr = part(start,end);

            node pivotminus;
            node pivotplus;

            if(arr[PIVOT]==this.start.next)
            {
                pivotminus = arr[PIVOT];
            }

            else
            {
                pivotminus = start;
                while(pivotminus.next!=arr[PIVOT])
                {
                    pivotminus = pivotminus.next;
                }
            }

            if(arr[PIVOT]==end)
            {
                pivotplus = arr[PIVOT];
            }
            else
            {
                pivotplus = arr[PIVOT].next;
            }

            sort(arr[START],pivotminus);
            sort(pivotplus,arr[END]);
        }
    }

    private final int START = 0;
    private final int PIVOT = 1;
    private final int END = 2;

    //partitions the linked list and returns the start,end and location of pivot

    node[] part(node start,node end)
    {
        node firstlink = start;
        node lastlink = end;
        node pivot = end;

        for(node i = start;i!=end;i=i.next)
        {
            if(i.value>pivot.value)
            {
                if(i==firstlink)
                {
                    firstlink = i.next;
                }

                delete(i);
                insert(i.value,lastlink);
                lastlink = lastlink.next;
            }
        }

        node[] arr = new node[3];
        arr[START]=firstlink;
        arr[PIVOT]=pivot;
        arr[END]=lastlink;

        return arr;
    }

    //prints the linked list

    void print()
    {
        node run = start.next;

        while(run!=null)
        {
            System.out.print(" "+run.value);
            run = run.next;
        }
    }

    public static void main(String[] args)
    {
        LinkedListSingle MyList = new LinkedListSingle();

        for(int i=500;i>0;i--)
        {
            MyList.insert(i);
        }
        System.out.print("Original List : ");
        MyList.print();
        MyList.qsort();
        System.out.print("\n\nList after sorting : ");
        MyList.print();
    }
}
