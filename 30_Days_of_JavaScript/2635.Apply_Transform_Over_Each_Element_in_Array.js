// https://leetcode.com/problems/apply-transform-over-each-element-in-array/description/?envType=study-plan-v2&envId=30-days-of-javascript


/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    returnedArray = [];
    let n = arr.length;
    for(let v=0; v<n; v++){
        let res = fn(arr[v], v);
        returnedArray.push(res);
    }
    return returnedArray;
};

