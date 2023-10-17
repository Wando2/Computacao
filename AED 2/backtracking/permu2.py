def permute(nums):
    def backtrack(resultList, tempList, nums):
        if len(tempList) == len(nums):
            resultList.append(tempList[:])
            return

        for number in nums:
            if number in tempList:
                continue

            tempList.append(number)
            backtrack(resultList, tempList, nums)
            tempList.pop()

    resultList = []
    backtrack(resultList, [], nums)
    return resultList

# Example usage:
result = permute([1, 2, 3])
print(result)