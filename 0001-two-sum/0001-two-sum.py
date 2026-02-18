class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen={}
        for i in range(len(nums)):
            need = target-nums[i]
            if need in seen:
                return [seen[need], i]
            seen[nums[i]]=i
        return []
        