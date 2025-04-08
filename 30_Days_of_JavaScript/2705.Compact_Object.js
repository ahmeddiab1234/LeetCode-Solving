// https://leetcode.com/problems/compact-object/description/?envType=study-plan-v2&envId=30-days-of-javascript

/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)){
        return obj.map(compactObject).filter(Boolean);
    }
    else if(obj!==null && typeof(obj)=="object"){
        let res = {};
        for(let key in obj){
            let val = compactObject(obj[key]);
            if(Boolean(val)){
                res[key] = val;
            }
        }
        return res;
    }
    else{
        return obj;
    }
};


