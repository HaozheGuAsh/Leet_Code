//Question# + Difficulty + Topic + Company + Similar_Question
//[15] [3 Sum] [Medium] [Array Two Pointers]
//[Amazon Microsoft Bloomberg Facebook Adobe Works Applications]
//[1 16 18 259].cpp

/* C++ Others*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;

        }

        return res;
    }
};


/*Java*/

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer> > res = new ArrayList<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {

            int target = -nums[i];
            int front = i + 1;
            int back = nums.length- 1;

            while (front < back) {

                int sum = nums[front] + nums[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    List<Integer> triplet = new ArrayList<Integer>();
                    triplet.add(nums[i]);
                    triplet.add(nums[front]);
                    triplet.add(nums[back]);
                    res.add(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet.get(1)) 
                    {
                        front++;
                    }

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet.get(1)) 
                    {
                        back--;
                    }
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < nums.length && nums[i + 1] == nums[i]) 
            {
                i++;
            }

        }

        return res;
    }
        
    
}
