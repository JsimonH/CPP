/* 前K个高频单词
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word 
with the lower alphabetical order comes first.

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order. */
    
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 统计出次数
        map<string, int> countMap;
        for(auto& e : words)
        {
            countMap[e]++;
        }

        // 按次数排序，且通过仿函数控制从大到小
        multimap<int, string, greater<int>> countSort;
        for(auto& kv : countMap)
        {
            countSort.insert(make_pair(kv.second, kv.first));
        }

        vector<string> v;
        for(auto e : countSort)
        {
            v.push_back(e.second);
            if(--k == 0)
                break;
        }

        return v;
    }
};
