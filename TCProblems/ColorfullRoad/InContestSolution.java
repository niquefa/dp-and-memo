import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class InContestSolution {
  public static int getMin(String road) {
    int len = road.length();
    int a[] = new int[len];
    for (int i = 0; i < len; i++)
      if (road.charAt(i) == 'G')
        a[i] = 0;
      else if (road.charAt(i) == 'B')
        a[i] = 1;
      else
        a[i] = 2;
    long dp[][] = new long[len][104];
    for (int i = 0; i < len; i++)
      for (int j = 0; j < 104; j++)
        dp[i][j] = -1;
    dp[0][0] = 0;
    for (int j = 0; j < 100; j++) {
      for (int i = 0; i < len; i++)
        if (dp[i][j] != -1) {
          int zhao = j % 3;
          for (int k = i; k < len; k++) {
            if (a[k] == zhao) {
              if (dp[k][j + 1] == -1 || dp[k][j + 1] > dp[i][j] + (k - i) * (k - i))
                dp[k][j + 1] = dp[i][j] + (k - i) * (k - i);
            }
          }
        }
    }
    long min = -1;
    for (int j = 0; j < 104; j++) {
      if (dp[len - 1][j] != -1 && (dp[len - 1][j] < min || min == -1))
        min = dp[len - 1][j];
    }
    return (int) min;
  }

  public static void main(String args[]) {
    Scanner sn = new Scanner(System.in);
    while (sn.hasNext()) {
      String road = sn.next();
      System.out.println(getMin(road));
    }
  }
}