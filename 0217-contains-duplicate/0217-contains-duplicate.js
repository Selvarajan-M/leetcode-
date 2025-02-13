/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let seen=new Set();
    for(let n of nums){
        if(seen.has(n)) return true;
        seen.add(n);
    }
    return false;
};