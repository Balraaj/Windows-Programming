/**
 * Created by Balraj on 20-08-2016.
 */

class wrap
{
    private int value;
    wrap obj;

    wrap(int x) {
        value = x;
    }

    int getvalue()
    {
        return value;
    }

}

class linkedlist
{
    private wrap top;
    private int count = 0;

    public void insert(int x)
    {
        count++;
        if(top==null)
        {
            top = new wrap(x);
        }

        else
        {
            wrap run = top;
            while(run.obj!=null)
            {
                run = run.obj;
            }

            run.obj = new wrap(x);
        }
    }

    public void insert(int x, int pos)
    {
        if(pos>count+1)
        {
            System.out.println("Error, position doesn't exist");
        }
        else if(pos==count+1)
        {
            insert(x);
        }
        else if (pos==1)
        {
            count++;
            wrap next = top;
            top = new wrap(x);
            top.obj = next;
        }
        else
        {
            count++;
            wrap prev = top;
            int temp = 2;

            while(temp!=pos)
            {
                temp++;
                prev = prev.obj;
            }

            wrap next = prev.obj;
            prev.obj = new wrap(x);
            prev.obj.obj = next;

        }
    }

    private wrap findprev(int x)
    {
        wrap run = top;
        wrap prev = top;

        while((run!=null)&&(run.getvalue()!=x))
        {
            prev = run;
            run = run.obj;
        }

        if(run.getvalue()==x)
        {
            return prev;
        }
        else
        {
            return null;
        }
    }

    public void remove(int x)
    {
        if(top.getvalue()==x)
        {
            count--;
            top = top.obj;
        }

        else
        {
            wrap prev = findprev(x);
            if(prev!=null)
            {
                count--;
                prev.obj = prev.obj.obj;
            }
            else
            {
                System.out.println("Error,value is not found");
            }

        }

    }
    private wrap findnode(int x)
    {
        wrap run = top;

        while((run.getvalue()!=x)&&(run.obj!=null))
        {
            run = run.obj;
        }

        if(run.getvalue()==x)
        {
            return run;
        }
        else
        {
            return null;
        }
    }

    public int length()
    {
        return count;
    }

    public void display()
    {
        wrap run = top;

        while(run != null)
        {
            System.out.println(run.getvalue());
            run = run.obj;
        }
    }


}

public class temp
{
    public static void main(String [] args)
    {
        linkedlist list = new linkedlist();


        for(int i = 0;i<10;i++)
        {
            list.insert(i);
        }

        list.display();

        System.out.println("\nDisplaying list after insertion at positions \n");
        list.insert(101,3);
        list.insert(303,1);
        list.remove(101);
        list.remove(303);
        list.remove(9);
        list.remove(1);
        list.display();

        System.out.println("\n\nLength of list is : "+list.length());
    }
}
