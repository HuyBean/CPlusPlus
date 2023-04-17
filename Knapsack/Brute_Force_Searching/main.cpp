#include <iostream>
#include <vector>

using namespace std;

pair<int, vector<int>> knapsack_brute_force(const vector<int> &values, const vector<int> &classes, const vector<int> &weights, int capacity)
{
    int n = values.size();
    int max_value = 0;
    vector<int> best_subset(n, 0);
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> subset(n, 0);
        int total_weight = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                subset[j] = 1;
                total_weight += weights[j];
            }
        }
        if (total_weight <= capacity)
        {
            vector<int> class_counts(classes.size(), 0);
            for (int j = 0; j < n; j++)
            {
                if (subset[j])
                {
                    class_counts[classes[j]]++;
                }
            }
            bool all_classes = true;
            for (int j = 0; j < classes.size(); j++)
            {
                if (class_counts[j] == 0)
                {
                    all_classes = false;
                    break;
                }
            }
            if (all_classes)
            {
                int value = 0;
                for (int j = 0; j < n; j++)
                {
                    if (subset[j])
                    {
                        value += values[j];
                    }
                }
                if (value > max_value)
                {
                    max_value = value;
                    best_subset = subset;
                }
            }
        }
    }
    return make_pair(max_value, best_subset);
}

int main()
{
    vector<int> values = {79, 32, 47, 18, 26, 85, 33, 40, 45, 59};
    vector<int> classes = {1, 1, 2, 1, 2, 1, 1, 2, 2, 2};
    vector<int> weights = {85, 26, 48, 21, 22, 95, 43, 45, 55, 52};
    int capacity = 101;
    auto result = knapsack_brute_force(values, classes, weights, capacity);
    cout << "Max value: " << result.first << endl;
    cout << "Best subset: ";
    for (int i = 0; i < result.second.size(); i++)
    {
        cout << result.second[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
