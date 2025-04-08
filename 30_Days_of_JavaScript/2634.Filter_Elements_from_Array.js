// https://leetcode.com/problems/filter-elements-from-array/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    filteredArr = [];
    let n=arr.length;
    for(let i=0; i<n; i++){
        let is_true = fn(arr[i], i);
        if(is_true){
            filteredArr.push(arr[i]);
        }
    }
    return filteredArr;
};