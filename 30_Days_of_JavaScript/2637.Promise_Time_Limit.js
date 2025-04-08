// https://leetcode.com/problems/promise-time-limit/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
        
    return async function(...args) {
        const fnPromise = fn(...args);
        const timeoutPromise = new Promise((_, reject) =>
            setTimeout(() => reject("Time Limit Exceeded"), t)
        );
        return Promise.race([fnPromise, timeoutPromise]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */

