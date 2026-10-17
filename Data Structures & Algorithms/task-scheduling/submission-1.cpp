class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();

        array<int, 26> counts = {};
        int unique_tasks_count = 0;
        for(char c : tasks)
        {
            if(counts[c-'A'] == 0)
                ++unique_tasks_count;
            ++counts[c-'A'];
        }

        int max_c = 0;
        int max_c_count = 0;
        int count_max_c_count = 0;
        for(int i=0;i<26;++i)
        {
            if(counts[i] > max_c_count)
            {
                max_c = i;
                max_c_count = counts[i];
                count_max_c_count = 1;
            }
            else if (counts[i] == max_c_count)
            {
                count_max_c_count++;
            }
        }

        int idle_count = (counts[max_c]-1) * n;
        cout<<idle_count<<" "<<max_c_count<<endl;
        if((unique_tasks_count - 1) <= n)
        {
            return max_c_count + idle_count + (count_max_c_count-1);
        }
        else
        {
            return tasks.size();
        }
    }
};
