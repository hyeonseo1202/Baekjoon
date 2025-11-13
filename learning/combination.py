def combination(nums,k):
    result = []
    
    def backtracking(start, curr):
        if len(curr) == k:
            result.append(curr[:])
            return
        for i in range(start, len(nums)):
            curr.append(nums[i])
            backtracking(i+1, curr)
            curr.pop()
    
    backtracking(start = 0, curr = [])
    return result

print(combination([1,2,3,4],2))