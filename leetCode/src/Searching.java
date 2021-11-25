import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Searching {

    int binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1; // 注意

        while (left <= right) { //!!<=
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1; // 注意
            else if (nums[mid] > target)
                right = mid - 1; // 注意
        }
        return -1;
    }

    int left_bound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        // 搜索区间为 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                // 搜索区间变为 [mid+1, right]
                left = mid + 1;
            } else if (nums[mid] > target) {
                // 搜索区间变为 [left, mid-1]
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 收缩右侧边界
                right = mid - 1;
            }
        }
        // 检查出界情况
        if (left >= nums.length || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 这里改成收缩左侧边界即可
                left = mid + 1;
            }
        }
        // 这里改为检查 right 越界的情况，见下图
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }

    public static void quickSort(int[] arr, int low, int high) {
        int p, i, j, temp;

        if (low >= high) {
            return;
        }
        //p就是基准数,这里就是每个数组的第一个
        p = arr[low];
        i = low;
        j = high;
        while (i < j) {
            //右边当发现小于p的值时停止循环
            while (arr[j] >= p && i < j) {
                j--;
            }

            //这里一定是右边开始，上下这两个循环不能调换（下面有解析，可以先想想）

            //左边当发现大于p的值时停止循环
            while (arr[i] <= p && i < j) {
                i++;
            }

            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        arr[low] = arr[i];//这里的arr[i]一定是停小于p的，经过i、j交换后i处的值一定是小于p的(j先走)
        arr[i] = p;
        quickSort(arr, low, j - 1);  //对左边快排
        quickSort(arr, j + 1, high); //对右边快排
    }

    //    public static void quickSort(int[] arr, int start, int end) {
//        // 如果区域内的数字少于 2 个，退出递归
//        if (start >= end) return;
//        // 将数组分区，并获得中间值的下标
//        int middle = partition(arr, start, end);
//        // 对左边区域快速排序
//        quickSort(arr, start, middle - 1);
//        // 对右边区域快速排序
//        quickSort(arr, middle + 1, end);
//    }
    // 将 arr 从 start 到 end 分区，左边区域比基数小，右边区域比基数大，然后返回中间值的下标
    public static int partition(int[] arr, int start, int end) {
        // 取第一个数为基数
        int pivot = arr[start];
        // 从第二个数开始分区
        int left = start + 1;
        // 右边界
        int right = end;
        // left、right 相遇时退出循环
        while (left < right) {
            // 找到第一个大于基数的位置
            while (left < right && arr[left] <= pivot) left++;
            // 交换这两个数，使得左边分区都小于或等于基数，右边分区大于或等于基数
            if (left != right) {
                exchange(arr, left, right);
                right--;
            }
        }
        // 如果 left 和 right 相等，单独比较 arr[right] 和 pivot
        if (left == right && arr[right] > pivot) right--;
        // 将基数和中间数交换
        if (right != start) exchange(arr, start, right);
        // 返回中间值的下标
        return right;
    }
    private static void exchange(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //[69. x 的平方根] easy
    //注意边界和返回
    //二分不要写递归 容易弄混
    public int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int i = 1;
        int j = x;
        int mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (mid > x / mid) {
                j = mid - 1;
            } else if (mid < x / mid) {
                i = mid + 1;
            } else {
                return mid;
            }
        }
        return j;

    }

    public int majorityElement(int[] nums) {
        majorityElementQS(0,nums.length-1,nums);
        return nums[nums.length/2];
    }

    public void majorityElementQS(int i,int j,int[] nums) {
        if (i>=j){
            return;
        }
        int cut=majorityElementPar(i,j,nums);
        majorityElementQS(i,cut-1,nums);
        majorityElementQS(cut+1,j,nums);

    }

    //[169. 多数元素]
    public int majorityElementPar(int i,int j,int[] nums) {
        int begin = i;
        int val=nums[i];
        while(i<j){

            while(i<j && nums[j]>=val) {
                j--;
            }
            while(i<j && nums[i]<=val) {
                i++;
            }
            majorityElementSwap(i,j,nums);

        }
        nums[begin]=nums[i];
        nums[i]=val;
        return j;
    }

    public void majorityElementSwap(int i,int j,int[] nums) {
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
//    public List<int[]> getCombination(int[] nums, int target){
//        HashSet<int[]> res=new HashSet<>();
//        HashSet<Integer> bucket = new HashSet<>();
//        for(int n:nums){
//            bucket.add(target-n);
//        }
//        for(int n:nums){
//            if (bucket.contains(n)){
//               res.add(new int[]{n,target-n});
//            }
//        }
//        return res.toArray();
//
//    }

    public double getMedian(int[] nums) {
        if (nums.length%2==0){
            return (getMedianQS(nums,0,nums.length-1,nums.length/2-1)+
                    getMedianQS(nums,0,nums.length-1,nums.length/2))/2.0;
        }
        return getMedianQS(nums,0,nums.length-1,nums.length/2);
    }

    public int getMedianQS(int[] nums,int start,int end,int target) {
        if (start>=end){
            return 0;
        }
        int i=start;
        int j=end;
        int axis = i;
        while (i<j){
            while (nums[j] >= nums[axis] && i < j) {
                j--;
            }
            while (nums[i] <= nums[axis] && i < j) {
                i++;
            }
            swap(nums,i,j);
        }
        nums[start] = nums[i];
        nums[i] = nums[axis];
        if (i==target){
            return nums[i];
        }
        if (i>target){
            return getMedianQS(nums,start,i-1,target);
        } else{
            return getMedianQS(nums,i+1,end,target);
        }
    }
    public void swap(int[] nums,int i,int j) {
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }


}

