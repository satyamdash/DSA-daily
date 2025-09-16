func containsDuplicate(nums []int) bool {
	mpp := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		mpp[nums[i]]++
		if mpp[nums[i]] > 1 {
			return true
		}
	}
	return false

}