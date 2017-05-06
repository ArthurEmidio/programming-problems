import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int c1 = in.nextInt();
            int c2 = in.nextInt();
            String people = in.next();

            int adults = 0;
            int kids = 0;

            for (int i = 0; i < n; i++) {
                if (people.charAt(i) == '0') kids++;
                else adults++;
            }

            long ans = 0;
            long add = (long) Math.sqrt(c1 / c2);

            long kidsPerAdult = 0;
            long adultsPerAdult = 0;
            if (add * adults < kids) {
                kidsPerAdult = kids / adults;
            } else {
                kidsPerAdult = Math.max(add, 1);
                adultsPerAdult = add;
            }

            while (kids > 0) {
                adults--;

                long kidsQuant = kidsPerAdult;
                long adultsQuant = 0;
                if (kidsQuant > kids) {
                    adultsQuant = Math.min(kidsQuant - kids, adults);
                    kidsQuant = kids;
                }

                ans += (c1 + c2*(kidsQuant + adultsQuant)*(kidsQuant + adultsQuant));
                kids -= kidsQuant;
                adults -= adultsQuant;
            }

            while (adults > 0) {
                adults--;
                long adultsQuant = adultsPerAdult;
                if (adultsQuant > adults) adultsQuant = adults;
                ans += c1 + c2*adultsQuant*adultsQuant;
                adults -= adultsQuant;
            }

            out.println(ans);
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
