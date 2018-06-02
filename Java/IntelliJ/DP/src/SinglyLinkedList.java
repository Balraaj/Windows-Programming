import java.util.HashSet;
import java.util.Stack;

/**
 * Created by Balraj on 30-Jan-18.
 *
 * This program implements a simple singly linked list.
 * This program contains many methods written to solve linked list problems in CTCI.
 */
public class SinglyLinkedList
{
    private class ListNode
    {
        int value;
        ListNode next;

        ListNode(int x)
        {
            value=x;
            next=null;
        }
    }

    private ListNode head,tail;

    private SinglyLinkedList()
    {
        head=tail=null;
    }

    private void insert(int x)
    {
        if(this.isEmpty())
        {
            head=tail=new ListNode(x);
        }
        else
        {
            tail.next=new ListNode(x);
            tail=tail.next;
        }
    }
    private boolean isEmpty()
    {
        return this.head==null;
    }

    private void printList()
    {
        ListNode runner = head;
        while(runner.next!=null)
        {
            System.out.print(runner.value+"->");
            runner=runner.next;
        }
        System.out.print(runner.value+"\n");
    }

    public void removeDuplicatesWithBuffer()
    {
        HashSet<Integer> mySet = new HashSet<>();
        mySet.add(this.head.value);
        ListNode previos = head;
        ListNode runner = previos.next;
        while(runner!=null)
        {
            if(mySet.contains(runner.value))
            {
                previos.next=runner.next;
            }
            else
            {
                mySet.add(runner.value);
                previos=previos.next;
            }
            runner=runner.next;
        }
    }

    private void removeDuplicatesWithoutBuffer()
    {
        ListNode runner = head;
        while(runner!=null)
        {
            ListNode current = runner.next;
            ListNode previous = runner;
            while(current!=null)
            {
                if(current.value==runner.value)
                {
                    previous.next=current.next;
                }
                else
                {
                    previous=previous.next;
                }
                current=current.next;
            }
            runner=runner.next;
        }
    }

    private int getTail()
    {
        return tail.value;
    }

    private void partitionQuickSortStyle(int partitionValue)
    {
        ListNode start = head;
        ListNode index = head;
        while(start!=null)
        {
            if(start.value < partitionValue)
            {
                int temp = start.value;
                start.value = index.value;
                index.value = temp;
                index = index.next;
            }
            start = start.next;
        }
    }

    private int returnKthToLast(int k)
    {
        ListNode p1 = head;
        ListNode p2 = head;

        for(int i=0;i<k;i++)
        {
            if(p1==null)
            {
                System.out.println("Failure");
                return 0;
            }
            else
            {
                p1=p1.next;
            }
        }

        while(p1!=null)
        {
            p1=p1.next;
            p2=p2.next;
        }
        return p2.value;
    }

    private SinglyLinkedList sumReverse(SinglyLinkedList secondList)
    {
        // This method calculates sum of two SinglyLinkedLists and returns a new SinglyLinkedList as result.
        // Each node of list stores one digit of the number and number is stored in reverse order. for example
        // list one is as :- 9->3->8->5 (5839)
        // list two is as :- 4->2->5->8 (8524)
        // result list is :- 3->6->3->4->1 (14363)

        ListNode runnerOne = this.head;
        ListNode runnerTwo = secondList.head;
        SinglyLinkedList myList = new SinglyLinkedList();
        int sum = 0;
        int carry = 0;

        while((runnerOne!=null)||(runnerTwo!=null))
        {
            sum = 0;
            if(runnerOne!=null)
            {
                sum+=runnerOne.value;
                runnerOne=runnerOne.next;
            }
            if(runnerTwo!=null)
            {
                sum+=runnerTwo.value;
                runnerTwo=runnerTwo.next;
            }

            sum+=carry;
            myList.insert(sum%10);
            carry=sum/10;
        }
        if(carry>0)
        {
            myList.insert(carry);
        }
        return myList;
    }

    private SinglyLinkedList sum(SinglyLinkedList secondList)
    {
        // This method calculates sum of two SinglyLinkedLists and returns a new SinglyLinkedList as result.
        // Each node of list stores one digit of the number. for example
        // list one is as :- 9->3->8->5
        // list two is as :- 4->2->5->8
        // result list is :- 1->3->6->4->3

        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();

        ListNode runnerOne = this.head;
        ListNode runnerTwo = secondList.head;
        SinglyLinkedList myList = new SinglyLinkedList();

        while((runnerOne!=null)||(runnerTwo!=null))
        {
            if(runnerOne!=null)
            {
                s1.push(runnerOne.value);
                runnerOne=runnerOne.next;
            }
            if(runnerTwo!=null)
            {
                s2.push(runnerTwo.value);
                runnerTwo=runnerTwo.next;
            }
        }

        int sum;
        int carry=0;
        while((!s1.isEmpty())||(!s2.isEmpty()))
        {
            sum = 0;
            if(!s1.isEmpty())
            {
                sum+=s1.pop();
            }
            if(!s2.isEmpty())
            {
                sum+=s2.pop();
            }

            sum+=carry;
            myList.insertInFront(sum%10);
            carry=sum/10;
        }

        if(carry>0)
        {
            myList.insertInFront(carry);
        }
        return myList;
    }

    private void insertInFront(int data)
    {
        // This method insert a new node with value=data in front of the list.
        // originally written as a helper method for sum
        ListNode temp = new ListNode(data);
        temp.next=this.head;
        this.head=temp;
    }
    public static void main(String[] args)
    {
        SinglyLinkedList myList = new SinglyLinkedList();

        myList.insert(9);
        myList.insert(3);
        myList.insert(8);
        myList.insert(5);
        System.out.println("First list is ");
        myList.printList();
        SinglyLinkedList myListOne = new SinglyLinkedList();
        myListOne.insert(4);
        myListOne.insert(2);
        myListOne.insert(5);
        myListOne.insert(8);
        System.out.println("Second list is ");
        myListOne.printList();
        SinglyLinkedList total = myList.sumReverse(myListOne);
        System.out.println("Sum of linked lists is ");
        total.printList();
    }
}
