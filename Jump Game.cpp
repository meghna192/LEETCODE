class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        reachable = 0
        for i, length in enumerate(nums):
            if i > reachable:
                break
            reachable = max(reachable, i + length)
        return reachable >= len(nums) - 1
  