import java.util.Scanner;

class BIT {
    private int N = 0;
    private long[] bit = null;

    public BIT(int N) {
        this.N = N;
        this.bit = new long[N + 1];
    }

    private int lowbit(int n) {
        return n & -n;
    }

    public void update(int i, long x) {
        while (i <= N) {
            this.bit[i] += x;
            i += this.lowbit(i);
        }
    }

    public long sum(int i) {
        long ret = 0;

        while (i > 0) {
            ret += this.bit[i];
            i -= this.lowbit(i);
        }
        return ret;
    }
}

public class Main {
    static BIT bit0, bit1;

    static void update(int l, int r, long x) {
        bit0.update(l, x);
        bit1.update(l, -(l - 1) * x);
        bit0.update(r + 1, -x);
        bit1.update(r + 1, r * x);
    }

    static long sum(int i) {
        return bit0.sum(i) * i + bit1.sum(i);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int N = cin.nextInt(), Q = cin.nextInt();

        bit0 = new BIT(N);
        bit1 = new BIT(N);

        for (int i = 1; i <= N; i++) {
            update(i, i, cin.nextInt());
        }

        while (Q-- > 0) {
            String type = cin.next();
            if (type.endsWith("Q")) {
                int l = cin.nextInt();
                int r = cin.nextInt();

                System.out.println(sum(r) - sum(l - 1));
            } else {
                int l = cin.nextInt();
                int r = cin.nextInt();
                long n = cin.nextLong();

                update(l, r, n);
            }
        }

        cin.close();
    }
}
