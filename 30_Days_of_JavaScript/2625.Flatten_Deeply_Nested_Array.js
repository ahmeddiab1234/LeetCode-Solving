// https://leetcode.com/problems/flatten-deeply-nested-array/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if(n===0){
        return arr;
    }
    let new_arr=[];
    const helper = function(arr, debth){
        for(let item of arr){
            if(Array.isArray(item)&&debth<n){
                helper(item, debth+1);
            }
            else{
                new_arr.push(item);
            }
        }
    }
    helper(arr,0);
    return new_arr;
};

