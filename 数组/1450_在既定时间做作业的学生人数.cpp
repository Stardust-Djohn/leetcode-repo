class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        vector<int> stuSchedule(1005, 0);
        for (int i = 0; i < startTime.size(); ++i)
        {
            stuSchedule[startTime[i]]++;
            stuSchedule[endTime[i] + 1]--;
        }
        // 求差分数组
        for (int i = 1; i < stuSchedule.size(); ++i)
        {
            stuSchedule[i] += stuSchedule[i - 1];
        }
        return stuSchedule[queryTime];
    }
};