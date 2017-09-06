/*
Question# + Difficulty + Topic + Company + Similar_Question
[Review] [280] [Wiggle Sort] [Medium] [Array Sort ] 
[Google ] 
[75 324].cpp
*/
/*
I have to say nobody explains the sufficiency of the following algo:

The final sorted nums needs to satisfy two conditions:

If i is odd, then nums[i] >= nums[i - 1];

If i is even, then nums[i] <= nums[i - 1].

The code is just to fix the orderings of nums that do not satisfy 1
and 2.
(from https://leetcode.com/discuss/57120/4-lines-o-n-c)

why is this greedy solution can ensure previous sequences and coming sequences W.R.T position i wiggled?

My explanation is recursive,

suppose nums[0 .. i - 1] is wiggled, for position i:

if i is odd, we already have, nums[i - 2] >= nums[i - 1],

if nums[i - 1] <= nums[i], then we does not need to do anything, its already wiggled.

if nums[i - 1] > nums[i], then we swap element at i -1 and i. Due to previous wiggled elements (nums[i - 2] >= nums[i - 1]), we know after swap the sequence is ensured to be nums[i - 2] > nums[i - 1] < nums[i], which is wiggled.

similarly,

if i is even, we already have, nums[i - 2] <= nums[i - 1],

if nums[i - 1] >= nums[i], pass

if nums[i - 1] < nums[i], after swap, we are sure to have wiggled nums[i - 2] < nums[i - 1] > nums[i].

The same recursive solution applies to all the elements in the sequence, ensuring the algo success.
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
                swap(nums[i], nums[i - 1]);
    }
};
