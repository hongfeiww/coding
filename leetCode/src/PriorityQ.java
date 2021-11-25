import java.util.PriorityQueue;

public class PriorityQ {

    // [295. 数据流的中位数]

    class MedianFinder {
        private PriorityQueue<Integer> large;
        private PriorityQueue<Integer> small;

        /** initialize your data structure here. */
        public MedianFinder() {
            // 小顶堆
            large = new PriorityQueue<>();
            // 大顶堆
            small = new PriorityQueue<>((a, b) -> {
                return b - a;
            });
        }

        public void addNum(int num) {

        }

        public double findMedian() {
            return 0;
        }
    }
}
