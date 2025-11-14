def subset(nums):
    result = []
    
    def backtracking(start, curr, k):
        if len(curr) == k:
            result.append(curr[:])
            return
        for i in range(start, len(nums)):
            curr.append(nums[i])
            backtracking(i+1, curr, k)
            curr.pop()
    for k in range(len(nums)):
        backtracking(start = 0, curr = [], k = k)
    return result

print(subset([1,2,3,4]))