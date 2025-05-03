class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotationsTop = 0, rotationsBottom = 0;
        int n = tops.size();

        for (int i = 0; i < n; i++) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            } else if (tops[i] != target) {
                rotationsTop++;
            } else if (bottoms[i] != target) {
                rotationsBottom++;
            }
        }

        return min(rotationsTop, rotationsBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;
        if (tops[0] != bottoms[0]) {
            return check(bottoms[0], tops, bottoms);
        }
        return -1;
    }
};