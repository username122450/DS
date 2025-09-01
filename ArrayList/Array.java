package ArrayList;

public class Array implements ArrayListt {
    //线性表顺序结构写法

    private int len;
    int[] ArrayList;
    int max = 20;


    @Override
    public void InitArray() {
        len = 0;
        ArrayList = new int[max];
    }

    @Override
    public boolean EndAdd(int k) {
        if (len > max) return false;
        ArrayList[len++] = k;
        return true;
    }

    @Override
    public boolean MiddleAdd(int k, int targer) {
        if (len > max) {
            System.out.println("List已满，添加失败");
            return false;
        }
        for (int i = len - 1; i >= targer; i--) {
            ArrayList[i] = ArrayList[i + 1];
        }
        ArrayList[targer] = k;
        len++;
        return true;
    }

    @Override
    public boolean HeadAdd(int k) {
        MiddleAdd(k,0);
        return true;
    }

    @Override
    public int Find(int k) {
        for (int i = 0; i < len; i++) {
            if (ArrayList[i] == k) {
                return i;
            }
        }

        return -1;
    }

    @Override
    public boolean Dalect(int k) {
        int index = Find(k);
        for (int i = index; i < len; i++) {
            ArrayList[i] = ArrayList[i + 1];
        }
        len--;
        return true;
    }

    @Override
    public boolean Revise(int k, int targer) {
        int index = Find(k);
        ArrayList[index] = k;
        return true;
    }

    @Override
    public void Print() {
        for (int i : ArrayList) {
            System.out.print(i + " ");
        }
        System.out.println();

    }
}
