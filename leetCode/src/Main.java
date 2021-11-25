import java.util.*;

public class Main {

    public static void main(String[] args) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        for (int i = 1; i < 8; i++) {
            nodes.put(i, new TreeNode(i));
        }
        nodes.get(1).left = nodes.get(2);
        nodes.get(1).right = nodes.get(3);
        nodes.get(2).left = nodes.get(4);
        nodes.get(2).right = nodes.get(5);
        nodes.get(3).left = nodes.get(6);
        nodes.get(3).right = nodes.get(7);
        nodes.get(1).flatten(nodes.get(1));
        Airbnb air = new Airbnb();
        BackTracing b  =new BackTracing();
//        System.out.println(nodes.get(1).bstFromPreorder(new int[]{
//                8, 5, 1, 7, 10, 12}));
        Searching s = new Searching();
        System.out.println(s.getMedian(new int[]{}));


    }

    public void tech() {

        StringBuilder sb = new StringBuilder();
        String s = sb.reverse().toString();
        //s.split();
        int a=0;
        int b = a==0?a:1;

       // s.substring()
        char[] chs=s.toCharArray();
        char x = Character.forDigit(1223, 16);

        int[] unsorted = {12, 3};


        Arrays.sort(unsorted);
        Integer[] l = {12, 3};
        Arrays.sort(l, Collections.reverseOrder());


        LinkedList<Integer> alist = new  LinkedList<Integer>();
        alist.poll();
      //  a.push();



    }

}
