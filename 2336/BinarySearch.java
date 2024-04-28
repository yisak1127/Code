//Yxw190038 yisak worku

public class BinarySearch {
    public static void main(String[] args) {
        BST bst = new BST();
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(1);
        bst.insert(4);
        bst.insert(9);
        bst.insert(6);
        bst.insert(2);
        bst.insert(8);
        bst.insert(10);

        System.out.println("Inorder Traversal:");
        bst.inorderTraversal();
    }
}


class Node {
    int val;
    Node leftChild;
    Node rightChild;
    Node parent;

    public Node(int val) {
        this.val = val;
        this.leftChild = null;
        this.rightChild = null;
        this.parent = null;
    }
}

class BST {
    Node root;

    public BST() {
        this.root = null;
    }

    public void insert(int val) {
        root = insertRecursive(root, val, null);
    }

    private Node insertRecursive(Node current, int val, Node parent) {
        if (current == null) {
            Node newNode = new Node(val);
            newNode.parent = parent;
            return newNode;
        }

        if (val < current.val) {
            current.leftChild = insertRecursive(current.leftChild, val, current);
        } else if (val > current.val) {
            current.rightChild = insertRecursive(current.rightChild, val, current);
        }

        return current;
    }

    public void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

    private void inorderTraversalRecursive(Node current) {
        if (current != null) {
            inorderTraversalRecursive(current.leftChild);
            System.out.print(current.val + " ");
            inorderTraversalRecursive(current.rightChild);
        }
    }
}

