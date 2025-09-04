class Solution {
public:
     string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        string result;
        int cycleLen = 2 * (numRows - 1);

        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < s.length(); i += cycleLen) {
                result += s[i];

                int diagonalIdx = i + cycleLen - 2 * row;
                if (row != 0 && row != numRows - 1 && diagonalIdx < s.length()) {
                    result += s[diagonalIdx];
                }
            }
        }

        return result;
    }
};