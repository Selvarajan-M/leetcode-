/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
    let freqMap = new Map();
    for (let n of nums) {
        freqMap.set(n, (freqMap.get(n) || 0) + 1);
    }
    let sorted = [...freqMap.entries()].sort((a, b) => b[1] - a[1]);
    return sorted.slice(0, k).map(([num])=>num);
};