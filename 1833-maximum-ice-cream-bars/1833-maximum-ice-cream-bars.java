class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int maxc = 0;

        for(int i = 0; i < costs.length; i++){
            if(costs[i] > maxc){
                maxc = costs[i];
            }
        }

        int[] cc = new int[maxc + 1];

        for(int i = 0; i < costs.length; i++){
            cc[costs[i]]++;
        }

        int c = 0;

        for(int i = 1; i <= maxc; i++){
            if(cc[i] == 0){
                continue;
            }
            if(coins < i){
                break;
            }

            for(int j = 0; j < cc[i]; j++){
                if(coins >= i){
                    coins -= i;
                    c++;
                }
            }
        }
        return c;
    }
}