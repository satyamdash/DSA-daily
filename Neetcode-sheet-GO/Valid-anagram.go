func isAnagram(s string, t string) bool {
	mpp := make(map[rune]int)

	for _, ch := range s {
		mpp[ch]++
	}

	for _, ch := range t {
		mpp[ch]--
	}

	for _, val := range mpp {
		if val != 0 {
			return false
		}
	}

	return true
}