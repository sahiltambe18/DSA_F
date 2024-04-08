class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        for (auto i : sandwiches) {
            if (q.front() == i) {
                q.pop();
            } else {
                int n = q.size(), j = 0;
                while (j < n && q.front() != i) {
                    q.push(q.front());
                    q.pop();
                    j++;
                }

                if (q.front() == i) {
                    q.pop();
                } else {
                    return q.size();
                }
            }
        }
        return 0;
    }
};