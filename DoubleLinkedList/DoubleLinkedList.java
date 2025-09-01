package DoubleLinkedList;

class CyclicDoubleLinkedList implements DoubleLinked {

    Node LinkedList;

    @Override
    public void InitLink() {
        LinkedList = new Node();
        LinkedList.next = LinkedList;
        LinkedList.pre = LinkedList;

    }

    @Override
    public boolean EndAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.next = LinkedList;
        s.pre = LinkedList.pre;
        LinkedList.pre.next = s;
        LinkedList.pre = s;
        return true;
    }

    @Override
    public boolean MiddleAdd(int k, int targer) {
        Node s = new Node();
        s.data = k;
        Node p = LinkedList.next;
        while (p != LinkedList && p.data != targer) {
            p = p.next;
        }
        if (p == LinkedList) {
            System.out.println("元素不存在，插入失败");
            return false;
        }
        s.pre = p;
        s.next = p.next;
        p.next.pre = s;
        p.next = s;

        return true;
    }

    @Override
    public boolean HeadAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.next = LinkedList.next;
        s.pre = LinkedList;
        LinkedList.next.pre = s;
        LinkedList.next = s;

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
    public boolean Delete(int k) {
        Node p = Find(k);
        if (p == null) {
            System.out.println("删除失败");
            return false;
        }
        p.pre.next = p.next;
        p.next.pre = p.pre;
        return true;
    }

    @Override
    public boolean Revise(int k, int target) {
        Node p = Find(target);
        if (p == null) {
            System.out.println("更换失败");
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

class test {
    public static void main(String[] args) {
        CyclicDoubleLinkedList dll = new CyclicDoubleLinkedList();
        dll.InitLink();
        dll.HeadAdd(1);
        dll.HeadAdd(2);
        dll.HeadAdd(3);
        dll.Print();
        dll.EndAdd(4);
        dll.EndAdd(5);
        dll.Print();
        dll.MiddleAdd(6, 1);
        dll.MiddleAdd(7, 3);
        dll.Print();
        dll.Delete(4);
        dll.Delete(5);
        dll.Print();
        dll.Revise(9, 2);
        dll.Print();
    }
}

public class DoubleLinkedList implements DoubleLinked {

    Node LinkedList;

    @Override
    public void InitLink() {

        LinkedList = new Node();
        LinkedList.next = null;
        LinkedList.pre = null;

    }

    @Override
    public boolean HeadAdd(int k) {
        Node s = new Node();
        s.data = k;
        s.pre = LinkedList;
        s.next = LinkedList.next;
        LinkedList.next = s;

        return true;
    }

    @Override
    public boolean EndAdd(int k) {
        Node s = new Node();
        s.data = k;
        Node p = LinkedList;
        while (p.next != null) {
            p = p.next;
        }
        s.next = null;
        s.pre = p;
        p.next = s;
        return true;
    }

    @Override
    public Node Find(int k) {
        Node p = LinkedList.next;
        while (p != null && p.data != k) {
            p = p.next;
        }
        if (p == null) {
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
        s.pre = p;
        p.next.pre = s;
        p.next = s;
        return true;
    }

    @Override
    public boolean Delete(int k) {
        Node p = Find(k);
        if (p == null) {
            System.out.println("删除失败");
            return false;
        }
        if (p.next != null) p.next.pre = p.pre;
        p.pre.next = p.next;
        return true;
    }

    @Override
    public boolean Revise(int k, int targer) {
        Node p = Find(targer);
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
        while (p != null) {
            System.out.print(p.data + "  ");
            p = p.next;
        }
        System.out.println();

    }
}
