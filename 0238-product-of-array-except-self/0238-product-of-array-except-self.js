/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    let n = nums.length;
    let leftProducts = new Map();
    let rightProducts = new Map();
    let result = new Array();
    leftProducts.set(0, 1);
    for (let i = 1; i < n; i++) {
        leftProducts.set(i, leftProducts.get(i - 1) * nums[i - 1]);
    }
    rightProducts.set(n - 1, 1);
    for (let i = n - 2; i >= 0; i--) {
        rightProducts.set(i, rightProducts.get(i + 1) * nums[i + 1])
    }
    for (let i = 0; i < n; i++) {
        result[i] = leftProducts.get(i) * rightProducts.get(i);
    }
    return result;
};