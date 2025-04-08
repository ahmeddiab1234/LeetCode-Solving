// https://leetcode.com/problems/allow-one-function-call/description/?envType=study-plan-v2&envId=30-days-of-javascript


/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let i=false;
    return function(...args){
        if(i){
            return undefined;
        }
        i=true;
        let res=fn(...args);
        return res;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
