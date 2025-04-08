// https://leetcode.com/problems/debounce/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timer;
    return function(...args) {
        return new Promise((resolve)=>{
            if(timer) clearTimeout(timer);
            timer = setTimeout(()=>{
                resolve(fn(...args));
            }, t)
        });
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */