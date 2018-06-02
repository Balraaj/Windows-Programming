package binarysearchtree;

public class BST
{
    private Node root;

    // This class defines the structure of BST node
    private static class Node
    {
        int value;
        int height;
        Node leftChild,rightChild,parent;
        Node(int value)
        {
            this.value=value;
            height=0;
            leftChild=rightChild=parent=null;
        }
    }

    BST()
    {
        root=null;
    }


    // returns node with the maximum value in subtree rooted at node
    Node maximum(Node node)
    {
        while(node.rightChild!=null)
        {
            node=node.rightChild;
        }
       return node;
    }

    //returns node with the minimum value in subtree rooted at node
    Node minimum(Node node)
    {
        while(node.leftChild!=null)
        {
            node=node.leftChild;
        }
        return node;
    }

    //returns successor of the node if exists otherwise returns null
    Node successor(Node node)
    {
        if(node.rightChild!=null)
        {
            return minimum(node.rightChild);
        }
        else
        {
            Node x = node;
            Node y = node.parent;

            while((y!=null)&&(x==y.rightChild))
            {
                x=y;
                y=y.parent;
            }
            return y;
        }
    }

    //returns predecessor of node
    Node predecessor(Node node)
    {
        if(node.leftChild!=null)
        {
            return maximum(node.leftChild);
        }
        else
        {
            Node x = node;
            Node y = node.parent;
            while((y!=null)&&(x==y.leftChild))
            {
                x=y;
                y=y.parent;
            }
            return y;
        }
    }

    //insertes a new node using the iterative procedure
    Node insertIterative(int value)
    {
        Node runner = root;
        Node previous=null;
        while(runner!=null)
        {
            previous=runner;
            if(value>runner.value)
                runner=runner.rightChild;
            else
                runner=runner.leftChild;
        }

        Node node = new Node(value);
        node.parent=previous;
        if(previous==null)
        {
            root = node;
        }
        else if(value>previous.value)
        {
            previous.rightChild = node;
        }
        else
        {
            previous.leftChild = node;
        }
        return node;
    }

    Node insertRecursive(Node node, int value)
    {
        if(node==null)
        {
            return new Node(value);
        }
        else if(value>node.value)
        {
            Node temp = insertRecursive(node.rightChild, value);
            if(temp!=node.rightChild)
            {
                node.rightChild=temp;
                temp.parent=node;
            }
        }
        else if(value<node.value)
        {
            Node temp = insertRecursive(node.leftChild, value);
            if(temp != node.leftChild)
            {
                node.leftChild = temp;
                temp.parent = node;
            }
        }
        return node;
    }

    Node insert(int value)
    {
        Node newNode = insertIterative(value);
        adjustHeight(newNode);
        return newNode;
    }

    void traverse(Node node)
    {
        if(node==null)
            return;
        traverse(node.leftChild);
        System.out.println(" Value is :  "+node.value+" and Height is : "+getHeight(node));
        traverse(node.rightChild);
    }

    //returns the node having value equal to value
    Node getNode(int value)
    {
        Node runner = root;
        while(runner!=null)
        {
            if(value==runner.value)
                break;
            else if(value>runner.value)
                runner=runner.rightChild;
            else
                runner=runner.leftChild;
        }
        return runner;
    }

    //sets the height of node
    void setHeight(Node node)
    {
        node.height=Math.max(getHeight(node.leftChild),getHeight(node.rightChild))+1;
    }

    //return height of node, if node is null then returns -1
    int getHeight(Node node)
    {
        if(node==null)
        {
            return -1;
        }
        else
        {
            return node.height;
        }
    }

    //check if height of parent has changed because of increase in the height of child
    boolean isHeightChanged(Node parent,Node child)
    {
        return ((parent!=null)&&(getHeight(parent)<getHeight(child)+1));
    }

    //adjusts height of all the nodes that may have been affected by the insertion
    void adjustHeight(Node child)
    {
        Node parent = child.parent;
        while(isHeightChanged(parent,child))
        {
            setHeight(parent);
            child=parent;
            parent=child.parent;
        }
    }

    public static void main(String[] args)
    {
        BST bst = new BST();
        bst.insert(10);
        bst.insert(30);
        bst.insert(5);
        bst.insert(50);
        bst.insert(20);
        bst.insert(1);
        bst.insert(3);
        bst.insert(66);
        bst.insert(6);
        bst.insert(7);
        bst.insert(8);
        bst.insert(25);
        bst.insert(45);
        bst.insert(78);
        bst.insert(89);
        bst.insert(90);
        bst.traverse(bst.root);
        //System.out.println("This node is : "+bst.getNode(8).value);
        System.out.println("\nSuccessor of 89 : "+bst.successor(bst.getNode(89)).value);
        System.out.println("\nSuccessor of 25 : "+bst.successor(bst.getNode(25)).value);
        Node node = bst.successor(bst.getNode(90));
        if(node==null)
        {
            System.out.println("\n\n This node doesn't have a successor");
        }
        else
        {
            System.out.println("\n\nSuccessor of 90 : "+node.value);
        }
    }
}