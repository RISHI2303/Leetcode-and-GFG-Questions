class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unrealizedCustomers = 0;

        for (int i = 0; i < minutes; i++) {
            unrealizedCustomers += customers[i] * grumpy[i];
        }

        int maxUnrealizedCustomers = unrealizedCustomers;
        for (int i = minutes; i < n; i++) {
            unrealizedCustomers += customers[i] * grumpy[i];
            unrealizedCustomers -= customers[i - minutes] * grumpy[i - minutes];

            maxUnrealizedCustomers =
                max(maxUnrealizedCustomers, unrealizedCustomers);
        }

        int totalCustomers = maxUnrealizedCustomers;

        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }
        
        return totalCustomers;
    }
};