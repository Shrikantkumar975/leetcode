/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (typeof classFunction !== 'function' || !classFunction.prototype) {
        return false;
    }

    if (obj === null || obj === undefined) {
        return false;
    }

    while(obj['__proto__']!==null && obj['__proto__'] !== classFunction.prototype){
        obj = obj['__proto__']
    }

    if(obj['__proto__'] === null) return false;

    return true;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */