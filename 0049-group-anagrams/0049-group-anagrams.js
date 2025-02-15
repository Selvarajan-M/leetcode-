/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let obj={};
        for(let str1 of strs){
            let sorted=str1.split('').sort().join('');
            if(obj[sorted]){
                obj[sorted].push(str1);
            }
            else{
                obj[sorted]=[str1];
            }

        }
        return Object.values(obj);
    
};