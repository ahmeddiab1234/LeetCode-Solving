// https://leetcode.com/problems/function-composition/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    let n = functions.length;
    return function(x) {
        if(n==0){
            return x;
        }
        let res=functions[n-1](x);
        for(let i=n-2; i>=0; i--){
            res = functions[i](res);
        }
        return res;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */