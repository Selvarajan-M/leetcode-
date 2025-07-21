class Solution {
    public boolean checkDivisibility(int n) {
        int original=n;
        int sumDigit=0;
        int productDigit=1;

        while(n>0){
            int digit =n % 10;
            sumDigit+=digit;
            productDigit*=digit;
            n /=10;
        }
        return (original%(sumDigit+productDigit)==0);
    }
}