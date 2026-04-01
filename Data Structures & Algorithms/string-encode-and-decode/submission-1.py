class Solution:

    def encode(self, strs: List[str]) -> str:
        ans=""
        for st in strs:
            ans=ans+' /'+st
        return ans
    def decode(self, s: str) -> List[str]:
        ans=s.split(' /')
        ans.remove("")
        return ans
