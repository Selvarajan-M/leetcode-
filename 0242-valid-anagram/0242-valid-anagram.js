/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!==t.length) return false;
    let count=new Array(26).fill(0);
    for(let i=0;i<s.length;i++){
        count[s.charCodeAt(i)-97]++;
        count[t.charCodeAt(i)-97]--;
    }
    return count.every(v=>v===0);
};