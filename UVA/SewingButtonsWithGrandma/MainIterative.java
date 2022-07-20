import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

//online judge http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3738

public class MainIterative {

    public static BigInteger[][] comb;

    /*
     * comb(n, k) = comb(n - 1, k - 1) + comb(n - 1, k);
     *
     */
    public static void calcCombinations(int limit) {
        comb = new BigInteger[limit + 1][limit + 1];

        for (int i = 0; i <= limit; i++) {
            Arrays.fill(comb[i], BigInteger.ZERO);
            comb[i][0] = BigInteger.ONE;
            comb[i][i] = BigInteger.ONE;
        }

        for (int i = 2; i <= limit; i++) {
            for (int j = 1; j < limit; j++) {
                comb[i][j] = comb[i - 1][j - 1].add(comb[i - 1][j]);
            }
        }
    }

    public static BigInteger C(int n, int k) {
        return comb[n][k];
    }

    public static void main(String[] args) throws Exception {
        //System.setIn(new FileInputStream("buttons.in"));

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        calcCombinations(50);

        StringTokenizer st = new StringTokenizer(bf.readLine().trim());
        int m = Integer.parseInt(st.nextToken());
        int kinds = Integer.parseInt(st.nextToken());

        while (m != 0 || kinds != 0) {
            int[] buttons = new int[kinds];

            for (int i = 0; i < kinds; i++)
                buttons[i] = Integer.parseInt(bf.readLine().trim());

            BigInteger[][] dp = new BigInteger[m + 1][kinds + 1];
            for (int i = 0; i <= kinds; i++)
                dp[0][i] = BigInteger.ONE;
            for (int i = 1; i <= m; i++)
                dp[i][kinds] = BigInteger.ZERO;

            for (int i = kinds - 1; i >= 0; i--) {
                for (int j = 0; j <= m; j++) {
                    dp[j][i] = BigInteger.ZERO;
                    for (int take = 0; take <= buttons[i]; take++) {
                        if (take > j)
                            break;

                        BigInteger count = C(j, take).multiply(dp[j - take][i + 1]);
                        dp[j][i] = dp[j][i].add(count);
                    }
                }
            }

            System.out.println(dp[m][0]);

            st = new StringTokenizer(bf.readLine().trim());
            m = Integer.parseInt(st.nextToken());
            kinds = Integer.parseInt(st.nextToken());
        }
    }
}
