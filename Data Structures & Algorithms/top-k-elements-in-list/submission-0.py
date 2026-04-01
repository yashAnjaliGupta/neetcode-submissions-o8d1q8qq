class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans=[]
        mp={}
        for num in nums:
            mp[num]=mp.get(num,0)+1 
        freq=mp.values()
        ans=[keys for keys,values in sorted(mp.items(),key=lambda mp:mp[1],reverse=True)]
        print(ans)
        return ans[:k]
