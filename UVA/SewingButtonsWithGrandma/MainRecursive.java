import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

// online judge http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3738

public class MainRecursive {

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

  public static int m;
  public static int kinds;
  public static int[] buttons;
  public static BigInteger dp[][];

  public static BigInteger f(int m, int t) {
    if (m == 0)
      return BigInteger.ONE;
    if (t >= kinds)
      return BigInteger.ZERO;

    if (dp[m][t] != null)
      return dp[m][t];

    BigInteger count = BigInteger.ZERO;
    int buttonsICanUse = Math.min(m, buttons[t]);
    for (int i = 0; i <= buttonsICanUse; i++) {
      BigInteger ways = C(m, i).multiply(f(m - i, t + 1));

      count = count.add(ways);
    }

    return dp[m][t] = count;
  }

  public static void main(String[] args) throws Exception {
    //System.setIn(new FileInputStream("buttons.in"));

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    calcCombinations(50);

    StringTokenizer st = new StringTokenizer(bf.readLine().trim());
    m = Integer.parseInt(st.nextToken());
    kinds = Integer.parseInt(st.nextToken());

    while (m != 0 || kinds != 0) {
      buttons = new int[kinds];

      for (int i = 0; i < kinds; i++)
        buttons[i] = Integer.parseInt(bf.readLine().trim());

      dp = new BigInteger[m + 1][kinds];

      System.out.println(f(m, 0));

      st = new StringTokenizer(bf.readLine().trim());
      m = Integer.parseInt(st.nextToken());
      kinds = Integer.parseInt(st.nextToken());
    }

  }

}