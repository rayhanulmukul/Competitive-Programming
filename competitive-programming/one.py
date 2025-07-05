class Solution:
    def findLHS(self, nums: List[int]) -> int:
        num_count = Counter(nums)
        max_length = 0
        for num in num_count:
            if num + 1 in num_count:
                max_length = max(max_length, num_count[num] + num_count[num + 1])
        return max_length