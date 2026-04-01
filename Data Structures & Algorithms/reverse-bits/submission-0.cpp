class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r=0;
        for(int i=0;i<32;i++){
            r=r<<1;
            r+=n%2;
            
            n=n/2;
        }
        return r;
    }
};
