// https://leetcode.com/problems/array-reduce-transformation/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let n = nums.length;
    let val = init;
    for (let i = 0; i < n; i++) {
        val = fn(val, nums[i]);
    }
    return val;
};