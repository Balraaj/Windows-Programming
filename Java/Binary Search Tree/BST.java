import javax.lang.model.util.ElementScanner6;

public class BST
{
    private class Node
    {
        int value;
        int height;
        Node leftChild,rightChild,parent;
        public Node(int value)
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
    Node root;
    // returns node with the maximum value in subtree rooted at root
    public Node maximum(Node root)
    {
        Node x = root;
        while(x.rightChild!=null)
        {
            x=x.rightChild;
        }

        return x;
    }

    //returns node with the minimum value in subtree rooted at root
    public Node minimum(Node root)
    {
        Node x = root;
        while(x.leftChild!=null)
        {
            x=x.leftChild;
        }
        return x;
    }

    //returns successor of the node
    public Node successor(Node node)
    {
        if(node.rightChild!=null)
        {
            return minimum(node.rightChild);
        }
        else
        {
            System.out.println("its second case");
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
    public Node predecessor(Node node)
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

    //insertes a new node
    public void insert(int value)
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
        if(previous==null)
            root = node;
        else if(value>previous.value)
            previous.rightChild=node;
        else 
            previous.leftChild=node;

        node.parent=previous;
    }

    public Node put(Node node,int value)
    {
        if(node==null)
            return new Node(value);
        if(value>node.value)
            node.rightChild=put(node.rightChild,value);
        else if(value<node.value)
            node.leftChild=put(node.leftChild,value);
        
        return node;
    }
    public void traverse(Node node)
    {
        if(node==null)
            return;
        traverse(node.leftChild);
        System.out.print(" "+node.value);
        traverse(node.rightChild);
    }

    public Node getNode(int value)
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
        bst.traverse(bst.root);
        //System.out.println("This node is : "+bst.getNode(8).value);
        System.out.println("\nSuccessor of 8 : "+bst.successor(bst.getNode(8)).value);
    }
} 