import java.util.*;

public class ListNode {

    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    // 206. 反转链表 Easy
    // linklist 都要画出来看思路 注意head和tail
    // 造一个prehead 最后返回 prehead.next ListNode hair = new ListNode(0);

    public ListNode reverseList3(ListNode head) { //TODO
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }

    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    public ListNode[] reverseList2(ListNode head) {
        ListNode[] res = new ListNode[2];
        res[1] = head;
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        res[0] = pre;
        return res;
    }

    //[19. 删除链表的倒数第 N 个结点] Medium
    // 双指针 快慢指针

    // [496. 下一个更大元素 I] easy
    // 单调栈
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        LinkedList<Integer> stack = new LinkedList<>();
        HashMap<Integer, Integer> res = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            int n = nums2[i];
            if (stack.isEmpty()) {
                stack.push(n);
            } else {
                //System.out.println("top: "+stack+n);
                while (!stack.isEmpty() && n > stack.peek()) {
                    res.put(stack.pop(), n);
                    //System.out.println("top2: "+res);
                }
                stack.push(n);
            }
            // System.out.println("res: "+stack+res);
        }


        while (!stack.isEmpty()) {
            int n = stack.pop();
            res.put(n, -1);
        }
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            result[i] = res.getOrDefault(nums1[i], -1);
        }
        return result;
    }

    //sliding window 解决一大类子字符串匹配的问题

//    int left = 0, right = 0;
//
//while (right < s.size()) {
//        // 增大窗口
//        window.add(s[right]);
//        right++;
//
//        while (window needs shrink) {
//            // 缩小窗口
//            window.remove(s[left]);
//            left++;
//        }
//    }

    // [76. 最小覆盖子串] Hard bug！！！！ equals 和 ==
    // 滑动窗口 逻辑问题
    public String minWindow(String s, String t) {

        String res = s + t;
        HashMap<Character, Integer> memo = new HashMap<Character, Integer>();
        HashMap<Character, Integer> tmap = new HashMap<Character, Integer>(); //need times
        for (int i = 0; i < t.length(); i++) {
            Character ch = t.charAt(i);
            tmap.put(ch, tmap.getOrDefault(ch, 0) + 1);
            memo.put(ch, 0);
        }
        //System.out.println("begin: "+tmap);
        int tcnt = tmap.size(); //need letter types
        int left = 0;
        int right = 0;
        while (right < s.length()) {
            //System.out.println("pt: "+left+right+memo+tcnt);
            Character ch = s.charAt(right);
            //System.out.println("ch: "+ch);
            if (memo.containsKey(ch)) { //match t
                memo.put(ch, memo.get(ch) + 1);
                if (memo.get(ch).equals(tmap.get(ch))) { //DEBUG！！
                    tcnt--;
                }
                if (tcnt == 0) { //valid window
                    while (tcnt == 0 && left < s.length()) { //contract
                        Character chl = s.charAt(left);
                        if (memo.containsKey(chl)) {
                            memo.put(chl, memo.get(chl) - 1);
                        }
                        if (memo.getOrDefault(chl, 0) < tmap.getOrDefault(chl, 0)) { //not valid
                            tcnt++;
                        }
                        left++;
                    }
                    String tmpRes = s.substring(left - 1, right + 1);
                    if (tmpRes.length() < res.length()) {
                        res = tmpRes;
                    }
                    //System.out.println("new left: "+left+tmap);
                    // new window
                    //System.out.println("new left2: "+left+tmap);
                }
            }
            right++;
        }
        if (res.length() > s.length()) {
            return "";
        }
        return res;
    }

    //
    //[1423. 可获得的最大点数]
    public int maxScore(int[] cardPoints, int k) {
        int windowSize = cardPoints.length-k;
        int maxSum = 0;
        int winSum = 0; //debug：需要windows值

        int i=0;
        int sum=0;
        for (;i<windowSize;i++){
            winSum+=cardPoints[i];
            sum+=cardPoints[i];
            // System.out.println(sum);
        }
        maxSum=winSum;
        for (;i<cardPoints.length;i++){ //debug,i已经是后一个了
            winSum=winSum+cardPoints[i]-cardPoints[i-windowSize];
            maxSum=Math.min(maxSum,winSum);
            sum+=cardPoints[i];
            // System.out.println(sum);
        }
        //System.out.println(sum);
        // System.out.println(maxSum);
        return sum-maxSum;


    }


    // [3. 无重复字符的最长子串]
    // 双指针 注意细节 画图 考虑周全
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        HashMap<Character, Integer> memo = new HashMap<>();
        int left = 0;
        int right = 0;
        while (right < s.length()) {
            Character ch = s.charAt(right);
            //System.out.println("left,right, ch:"+left+right+ch);
            //System.out.println("res,map:"+res+memo);
            if (memo.containsKey(ch) && memo.get(ch) >= left) { //reset
                int loc = memo.get(ch);
                // System.out.println("loc:"+loc);
                left = loc + 1;
            }
            if (right - left + 1 > res) {
                res = right - left + 1;
            }
            memo.put(ch, right);
            right++;

        }
        return res;
    }

    //剑指 Offer 59 - I. 滑动窗口的最大值
    //单调栈
//    public int[] maxSlidingWindow(int[] nums, int k) {
//
//    }
    //*****************************//

    // [1. 两数之和] [167] TODO
    // "重复" "相同" -》 hash
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            memo.put(target - numbers[i], i);
        }
        for (int i = 0; i < numbers.length; i++) {
            if (memo.containsKey(numbers[i])) {
                int idx = memo.get(numbers[i]);
                return new int[]{Math.min(idx, i) + 1, Math.max(idx, i) + 1};
            }
        }
        return new int[]{-1, -1};
    }

    // [337. 打家劫舍 III] medium
    // tree dp
    // 树就想到遍历 post traversal

    HashMap<TreeNode, Integer> yes = new HashMap<>();
    HashMap<TreeNode, Integer> no = new HashMap<>();

    public int rob(TreeNode root) {
        return Math.max(robDfs(root, true), robDfs(root, false));
    }

    public int robDfs(TreeNode root, boolean rob) {
        if (root == null) {
            return 0;
        }
        int lno;
        if (no.containsKey(root.left)) {
            lno = no.get(root.left);
        } else {
            lno = robDfs(root.left, false);
            no.put(root.left, lno);
        }
        int rno;
        if (no.containsKey(root.right)) {
            rno = no.get(root.right);
        } else {
            rno = robDfs(root.right, false);
            no.put(root.right, rno);
        }
        if (rob) {
            return lno + rno + root.val;
        }
        int lyes;
        if (yes.containsKey(root.left)) {
            lyes = yes.get(root.left);
        } else {
            lyes = robDfs(root.left, true);
            yes.put(root.left, lyes);
        }
        int ryes;
        if (yes.containsKey(root.right)) {
            ryes = yes.get(root.right);
        } else {
            ryes = robDfs(root.right, true);
            yes.put(root.right, ryes);
        }
        return Math.max(lyes, lno) + Math.max(ryes, rno);
    }


    //[剑指 Offer II 001. 整数除法] easy TODO
    // （凡是 不能用乘除法，或者要求优化 乘除法的性能问题，都可以优先考虑 位运算）

    // [剑指 Offer 52. 两个链表的第一个公共节点] easy
    // 利用长度
//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//
//    }


    //一个整数只能由6和8构成以6866688688这样的自然顺序给定一个K问第K个这样的数字是多少

    //[143. 重排链表]
    // reorder LinkedList: 1-2-3-4-5-6 变成 1-6-2-5-3-4
//    public void reorderList(ListNode head) {
//
//    }

    public void palindromePairs(String[] words) {
        HashMap<String,Integer> reversedWordsMap = new   HashMap<>();//word,index
        int wIdx=0;
        for (String w:words){
            reversedWordsMap.put(getRreversedWord(w),wIdx);
            wIdx++;
        }
        List<List<Integer>> resList = new ArrayList<>();
        wIdx=0;
        for (String word:words){
            int len = word.length();
            for(int i=0;i<len;i++){
                if (palindromePairsSubJudge(word.substring(0,i+1)) && reversedWordsMap.containsKey(word.substring(i))) {
                    List<Integer> singleResList = new ArrayList<>();
                    singleResList.add(wIdx);
                    singleResList.add(reversedWordsMap.get(word.substring(i)));
                    resList.add(singleResList);
                }
                if (palindromePairsSubJudge(word.substring(i)) && reversedWordsMap.containsKey(word.substring(0,i))) {
                    List<Integer> singleResList = new ArrayList<>();
                    singleResList.add(wIdx);
                    singleResList.add(reversedWordsMap.get(word.substring(i)));
                    resList.add(singleResList);
                }
            }
            wIdx++;
        }

    }


    public boolean palindromePairsSubJudge(String word) {
        int len = word.length();
        for(int i=0;i<len/2;i++){
            if (word.charAt(i)!=word.charAt(len-i-1)){
                return false;
            }
        }
        return true;
    }


    public String getRreversedWord(String word) {
        String res=word;
        int len = word.length();
//        for(int i=0;i<len/2;i++){
//            res.(word.charAt(len-i-1),res);
//            res.charAt(len-i-1)=word.charAt(i);
//        }
        return res;
    }


    //[88. 合并两个有序数组] easy
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1;
        int j=n-1;
        int idx=m+n-1;
        while (i>=0 || j>=0) {

            if (i<0) {
                nums1[idx]=nums2[j];
                idx--;
                j--;
                continue;
            }

            if (j<0) {
                nums1[idx]=nums1[i];
                idx--;
                i--;
                continue;
            }

            if (nums1[i]>nums2[j]) {
                nums1[idx]=nums1[i];
                i--;
            }else {
                nums1[idx]=nums2[j];
                j--;
            }
            idx--;
        }
        return;

    }
    //[238. 除自身以外数组的乘积] m
    //时间复杂度 空间复杂度的优化
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        int mul=1;
        res[0]=1;
        for (int i=1;i<nums.length;i++){
            mul*=nums[i-1];
            res[i]=mul;
        }
        mul=1;
        for (int i=nums.length-2;i>=0;i--){
            mul*=nums[i+1];
            res[i]*=mul;
        }
        return res;
    }
    //[680. Valid Palindrome II] easy
    public boolean validPalindrome(String s) {
        int start=0;
        int end=s.length()-1;
        while (start<end){
            if(s.charAt(start)!=s.charAt(end)){
                return validPalindromeIsP(s,start+1,end)|| validPalindromeIsP(s,start,end-1);
            }
        }
        return true;
    }

    public boolean validPalindromeIsP(String s,int start,int end) {
        if (start>=end){
            return true;
        }
        while (start<end){
            if(s.charAt(start)!=s.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return false;


    }

}