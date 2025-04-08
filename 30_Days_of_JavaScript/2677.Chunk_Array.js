// https://leetcode.com/problems/chunk-array/description/?envType=study-plan-v2&envId=30-days-of-javascript


/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let tot_arr = [];
    for(let i=0; i<arr.length;){
        let k=0;
        let sub_arr=[];
        while(k<size&& i<arr.length){
            sub_arr.push(arr[i]);
            k++,i++;
        }
        tot_arr.push(sub_arr);
    }
    return tot_arr;
};
