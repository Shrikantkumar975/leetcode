/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let result = {};
    return function(...args) {
        const key = JSON.stringify(args);
        if (result.hasOwnProperty(key)) {
            return result[key];
        }
        const newResult = fn.apply(this, args);
        result[key] = newResult;
        return newResult
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */