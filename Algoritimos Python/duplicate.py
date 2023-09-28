class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
       hash = set()
       for i in range(len(nums)):
           if nums[i] in hash:
               return True
           hash.add(nums[i])
       return False         


           