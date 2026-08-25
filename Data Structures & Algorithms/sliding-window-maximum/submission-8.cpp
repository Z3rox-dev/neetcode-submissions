#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // contiene gli indici
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Rimuovi dalla testa se fuori dalla finestra
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Rimuovi dalla coda i valori più piccoli del nuovo numero
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Aggiungi il nuovo indice
            dq.push_back(i);

            // Aggiungi il massimo alla risposta, quando la finestra è piena
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
