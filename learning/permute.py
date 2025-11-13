#Q. nums = [1,2,3,4]로 만들 수 있는 모든 순열을 반환하시오.
def permute(nums): #permute: 순서를 바꾸다, 뒤섞다. 과학에선 '순열'
    def backtrack(curr):
        if len(curr) == len(nums):
            ans.append(curr[:]) #리스트의 복사본(curr[:])으로 넣어야 나중에 값에 영향 안받음
            return
                
        for num in nums:
            if num not in curr:
                curr.append(num)
                backtrack(curr)
                curr.pop()
        
    ans = []
    backtrack([])
    return ans



nums = [1,2,3,4]
print(permute(nums))