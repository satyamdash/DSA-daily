func groupAnagrams(strs []string) [][]string {
	result := make([][]string, 0)
	mpp := make(map[string][]string)

	for _, str := range strs {
		var arr [26]int
		for _, ch := range str {
			arr[ch-'a']++
		}

		key := strconv.Itoa(arr[0])
		for i := 1; i < 26; i++ {
			key += "," + strconv.Itoa(arr[i])
		}
		mpp[key] = append(mpp[key], str)
	}

	for _, val := range mpp {
		result = append(result, val)
	}

	return result

}