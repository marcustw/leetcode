/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = (nums) => {
    let c = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i]==nums[i-1]) c++;
        else nums[i-c]=nums[i];
    }
    return nums.length-c;
};