package LinkedList;

public class LinkedList implements Linked {

    Node LinkList;


    @Override
    public void InitLink() {
        LinkList = new Node();
        LinkList.next = null;
    }

    @Override
    public boolean EndAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.next = null;
        Node p = LinkList;
        while (p.next != null) {
            p = p.next;
        }
        p.next = s;
        return true;
    }

    @Override
    public boolean MiddleAdd(int k, int targer) {
        Node s = new Node();
        s.data = k;
        Node p = LinkList.next;
        while (p != null && p.data != targer) {
            p = p.next;
        }
        if (p == null) {
            return false;
        }

        s.next = p.next;
        p.next = s;
        return true;
    }

    @Override
    public boolean HeadAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.next = LinkList.next;
        LinkList.next = s;
        return true;
    }

    @Override
    public Node Find(int k) {
        Node p = LinkList.next;
        while (p != null && p.data != k) {
            p = p.next;
        }
        if (p == null) {
            System.out.println("数据不存在");
        }
        return p;
    }

    @Override
    public boolean Delete(int k) {
        Node p = LinkList;
        Node s = LinkList.next;
        while (s != null && s.data != k) {
            p = s;
            s = s.next;
        }
        if (s == null) {
            System.out.println("数据不存在");
            return false;
        }
        p.next = s.next;
        return true;
    }

    @Override
    public boolean Revise(int k, int larger) {
        Node p = Find(k);
        if (p == null) {
            System.out.println("插入失败");
            return false;
        }
        p.data = larger;
        return true;
    }

    @Override
    public void Print() {
        Node p = LinkList.next;
        while (p != null) {
            System.out.print(p.data + "  ");
            p = p.next;
        }
        System.out.println();
    }
}

class test {
    public static void main(String[] args) {
        CyclicLinkedList List = new CyclicLinkedList();
        List.InitLink();
        List.HeadAdd(1);
        List.HeadAdd(2);
        List.HeadAdd(3);
        List.Print();
        List.EndAdd(4);
        List.Print();
        List.EndAdd(5);
        List.Print();
        List.MiddleAdd(6, 1);
        List.MiddleAdd(7, 3);
        List.Print();
        List.Delete(4);
        List.Delete(5);
        List.Print();
        List.Revise(9, 2);
        List.Print();
    }
}

class CyclicLinkedList implements Linked {

    Node LinkedList;

    @Override
    public void InitLink() {
        LinkedList = new Node();
        LinkedList.next = LinkedList;
    }

    @Override
    public boolean HeadAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.next = LinkedList.next;
        LinkedList.next = s;

        return true;
    }

    @Override
    public boolean EndAdd(int k) {
        Node s = new Node();
        s.data = k;
        Node p = LinkedList;
        while (p.next != LinkedList) {
            p = p.next;
        }
        s.next = LinkedList;
        p.next = s;

        return true;
    }

    @Override
    public Node Find(int k) {
        Node p = LinkedList.next;
        while (p != LinkedList && p.data != k) {
            p = p.next;
        }
        if (p == LinkedList) {
            System.out.println("元素不存在");
            return null;
        }
        return p;
    }

    @Override
    public boolean MiddleAdd(int k, int target) {
        Node s = new Node();
        s.data = k;
        Node p = Find(target);
        if (p == null) {
            System.out.println("插入失败");
            return false;
        }
        s.next = p.next;
        p.next = s;
        return true;
    }

    @Override
    public boolean Delete(int k) {
        Node p = LinkedList;
        Node x = LinkedList.next;
        while (x != LinkedList && x.data != k) {
            p = x;
            x = x.next;
        }
        if (x == LinkedList) {
            System.out.println("元素不存在,删除失败");
            return false;
        }
        p.next = x.next;
        return true;
    }

    @Override
    public boolean Revise(int k, int target) {
        Node p = Find(target);
        if (p == null) {
            System.out.println("替换失败");
            return false;
        }
        p.data = k;
        return true;
    }

    @Override
    public void Print() {
        Node p = LinkedList.next;
        while (p != LinkedList) {
            System.out.print(p.data + "  ");
            p = p.next;
        }
        System.out.println();
    }
}

