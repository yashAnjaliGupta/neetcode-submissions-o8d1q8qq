func maxSlidingWindow(nums []int, k int) []int {
    n := len(nums)
    var q []int
    for i := 0; i < k; i++ {
        for len(q) > 0 && nums[q[len(q)-1]] < nums[i] {
            q = q[:len(q)-1]
        }
        q = append(q, i)
    }
    ans := make([]int, n-k+1)
    var j = 0
    for i := k; i < n; i++ {
        ans[j] = nums[q[0]]
        j++
        for len(q) > 0 && nums[q[len(q)-1]] < nums[i] {
            q = q[:len(q)-1]
        }
        for len(q) > 0 && q[0] < i-k+1 {
            q = q[1:]
        }
        q = append(q, i)
    }
    ans[j] = nums[q[0]]
    return ans
}
