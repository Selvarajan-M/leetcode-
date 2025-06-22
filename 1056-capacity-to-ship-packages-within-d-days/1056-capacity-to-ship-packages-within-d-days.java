class Solution {
    public int fun(int[] weights, int cap) {
        int day = 1, load = 0;
        for (int weight : weights) {
            if (load + weight > cap) {
                day++;
                load = weight;
            } else {
                load += weight;
            }
        }
        return day;
    }

    public int findMax(int[] weights) {
        int maxi = Integer.MIN_VALUE;
        for (int num : weights) {
            maxi = Math.max(maxi, num);
        }
        return maxi;
    }

    public int findSum(int[] weights) {
        int sum = 0;
        for (int num : weights) {
            sum += num;
        }
        return sum;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = findMax(weights), high = findSum(weights);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int noOfDays = fun(weights, mid);

            if (noOfDays <= days) {
                ans = mid;      // valid answer, try to minimize
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}
