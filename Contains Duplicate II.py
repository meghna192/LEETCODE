class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        lookup = {}
        for i, num in enumerate(nums):
            if num not in lookup:
                lookup[num] = i
            else:
                # If the value occurs before, check the difference.
                if i - lookup[num] <= k:
                    return True
                # Update the index of the value.
                lookup[num] = i
        return False