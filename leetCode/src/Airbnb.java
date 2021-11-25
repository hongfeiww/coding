import java.util.HashMap;

public class Airbnb {

    public int collatzConjecture(int n) {
        int max = 0;
        for (int i = 2; i <= n; i++) {
            int times = collatzConjectureRecur(i);
            mem.put(i, times);
            if (times > max) {
                max = times;
            }
        }
        return max;
    }

    HashMap<Integer, Integer> mem = new HashMap<>();

    // 优化：使用hashmap存储对应的结果，如果计算过就不用再计算
    public int collatzConjectureRecur(int i) {
        if (i == 1) {
            return 1;
        }
        if (mem.containsKey(i)) {
            return mem.get(i);
        }
        if (i % 2 == 0) {
            return 1 + collatzConjectureRecur(i / 2);
        }
        return 1 + collatzConjectureRecur(3 * i + 1);
    }

    class QueueWithFixedArray {}
}
