def twosum(nums, target):
    def backtrack(start, curr):
        if len(curr) == 2 and sum(nums[i] for i in curr) == target:
            return curr
        
        for i in range(start, len(nums)):
            curr.append(i)
            ret = backtrack(i+1, curr)
            
            if ret:
                return ret
            
            curr.pop()
        return None
    
    return backtrack(0, [])
        
# nums에서 합이 target이 되는 숫자 2개를 백트레킹으로 찾는 코드!      
print(twosum(nums = [4,9,7,5,1], target = 12))