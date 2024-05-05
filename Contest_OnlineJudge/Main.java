import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findMaxK(int[] nums) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        Map<Integer, Integer> mp = new HashMap<>();

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        for (int num : nums) {
            if (mp.containsKey(-num)) {
                mx = Math.max(mx, Math.abs(num));
            }
        }

        return mx == Integer.MIN_VALUE ? -1 : mx;
    }
}