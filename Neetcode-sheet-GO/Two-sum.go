func twoSum(nums []int, target int) []int {
	mpp := make(map[int]int)
	arr := []int{}

	for i, num := range nums {
		complement := target - num
		val, exists := mpp[complement]
		if exists {
			arr := append(arr, val, i)
			return arr
		}
		mpp[num] = i
	}
	return arr
}