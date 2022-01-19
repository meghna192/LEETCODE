class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        odds = 0
        for k, v in collections.Counter(s).iteritems():
            odds += v & 1
        return len(s) - odds + int(odds > 0)