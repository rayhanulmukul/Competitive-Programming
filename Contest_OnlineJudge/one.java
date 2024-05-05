import java.util.ArrayList;
import java.util.TreeMap;

class Solution{
    public ArrayList <Integer> verticalSum(Node root) {
        TreeMap<K,V> <Integer, Integer> tm = new TreeMap<>();
        ArrayList <Integer> list = new ArrayList<>();

        traverse(root, tm, 0);
        for(int i : tm.keySet()){
            list.add(tm.get(i));
        }

        return list;
    }
    public void traverse(Node root, TreeMap <Integer, Integer> tm, int i){
        if(root == null) return;
        if(tm.containsKey(i)) tm.put(i, root.data);
        else tm.put(i, tm.get(i) + root.data);

        traverse(root.left, tm, i - 1);
        traverse(root.right, tm, i + 1);
    }
}
