import java.util.*;

public class triangle_jm {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        in.close();
        int t = N;
        ArrayList<Integer> primes = new ArrayList<Integer>();
        for (int p = 2; p * p <= t; p++)
            while (t % p == 0) {
                primes.add(p);
                t /= p;
            }
        if (t > 1) primes.add(t);

        long count1 = 1, count2 = 1, count3 = 1, count4 = 1, count5 = 1, count6 = 1;
        for (int i = 0; i < primes.size(); i++) {
            long p = primes.get(i);
            int e = 1;
            while (i + 1 < primes.size() && p == primes.get(i + 1)) {
                e++;
                i++;
            }

            if (e == 1)
                count1 *= p * p;
            else if (e > 1) {
                int k = e / 2 + e % 2;

                if (p == 2 && e % 2 == 1)
                    count1 *= Power(2, 3 * k - 1) * (Power(2, k) - 1);
                else if (p == 2 && e % 2 == 0)
                    count1 *= Power(2, 3 * k) * (Power(2, k + 1) - 1);
                else if (e % 2 == 1)
                    count1 *= Power(p, 3 * k - 2) * (Power(p, k) + Power(p, k - 1) - 1);
                else
                    count1 *= Power(p, 3 * k - 1) * (Power(p, k + 1) + Power(p, k) - 1);
            }

            if (p == 2) {
                count2 *= e * Power(2, e);
                count3 *= Power(2, e);
                count5 *= Power(p, e);
                count6 *= Power(p, (e + 1) / 2);
            } else {
                count6 *= Power(p, e / 2);
                count2 *= ((p - 1) * e + p) * Power(p, e - 1);
                if (p % 4 == 3)
                    count3 *= Power(p, e - (e % 2));
                else
                    count3 *= ((p - 1) * e + p) * Power(p, e - 1);
                if (p % 8 == 1 || p % 8 == 7)
                    count5 *= ((p - 1) * e + p) * Power(p, e - 1);
                else
                    count5 *= Power(p, e - e % 2);
            }

            count4 *= Power(p, e / 2);
        }

        long solutions = (count1 + count5) / 2 - count2 - (count3 + count6) / 2 + count4;

        System.out.println(solutions);

    }

    static long Power(long b, long exp) {
        long v = 1;
        while (exp-- > 0)
            v *= b;
        return v;
    }

}