package LinkedList;

interface Linked {
    class Node {
        int data;
        Node next;
    }

    void InitLink();

    boolean HeadAdd(int k);

    boolean EndAdd(int k);

    Node Find(int k);

    boolean MiddleAdd(int k, int targer);

    boolean Delete(int k);

    boolean Revise(int k, int targer);

    void Print();

}
