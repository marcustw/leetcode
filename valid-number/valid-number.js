/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    return !s.includes("Infinity") && !isNaN(s);
};