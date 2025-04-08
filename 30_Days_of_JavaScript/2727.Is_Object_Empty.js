// https://leetcode.com/problems/is-object-empty/description/?envType=study-plan-v2&envId=30-days-of-javascript


/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    // if(Object.keys(obj).length===0){
    //     return true;
    // }
    // else {
    //     return false;
    // }
    return (JSON.stringify(obj) === "{}")||(JSON.stringify(obj) === "[]");
};