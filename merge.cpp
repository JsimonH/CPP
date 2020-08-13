/* 合并排序的数组
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
Initially the number of elements in A and B are m and n respectively.

Example:
Input:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int end = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j]) {
                A[end] = A[i];
                i--;
                end--;
            }
            else {
                A[end] = B[j];
                j--;
                end--;
            }
        }

        while(i >= 0) {
            A[end] = A[i];
            end--;
            i--;
        }
        while(j >= 0) {
            A[end] = B[j];
            end--;
            j--;
        }
    }
};
