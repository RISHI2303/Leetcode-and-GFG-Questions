class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maxPosition = max(findMax(seats), findMax(students));

        vector<int> differences(maxPosition, 0);
        
        for (int position : seats) {
            differences[position - 1]++;
        }

        for (int position : students) {
            differences[position - 1]--;
        }

        int moves = 0;
        int unmatched = 0;
        for (int difference : differences) {
            moves += abs(unmatched);
            unmatched += difference;
        }

        return moves;
    }

private:
    int findMax(const vector<int>& array) {
        int maximum = 0;
        for (int num : array) {
            if (num > maximum) {
                maximum = num;
            }
        }
        return maximum;
    }
};