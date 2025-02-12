/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if(n===0){
        return n;
    }
    else if(n===1){
        return n;

    }
    else{
        return fib(n-2)+fib(n-1);
    }
    
};