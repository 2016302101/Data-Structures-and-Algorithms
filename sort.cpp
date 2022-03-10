#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void countSort (vector<int>& nums);
int partition (vector<int>& nums, int start, int end); 
void quickSort (vector<int>& nums, int start, int end);
void mergeSort (vector<int>& nums);
void mergehelper (vector<int>& src, vector<int>& dst, int start, int end);
void bubbleSort (vector<int>& nums);
void selectionSort (vector<int>& nums);
void insertSort(vector<int>& nums);

int main() {
    vector<int> nums = {2, 3, 4, 2, 3, 2, 1};
    insertSort(nums);
    // selectionSort(nums);
    // bubbleSort(nums);
    // countSort(nums);
    // quickSort(nums, 0, nums.size() - 1);
    // mergeSort(nums);
    return 0;
}

void countSort (vector<int>& nums) {
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());
    vector<int> counts(max_num - min_num + 1);

    for (auto& num : nums) {
        counts[num - min_num]++;
    }

    int pos = 0;
    for (int i = 0; i < max_num - min_num + 1; ++i) {
        while (counts[i] > 0) {
            nums[pos++] = i + min_num;
            counts[i]--;
        }
    }
}

void quickSort (vector<int>& nums, int start, int end) {
    if (start > end)
        return;
    
    int pivot = partition(nums, start, end);
    quickSort(nums, start, pivot - 1);
    quickSort(nums, pivot + 1, end);
}

int partition (vector<int>& nums, int start, int end) {
    int random = rand() % (end - start + 1) + start;

    swap(nums[end], nums[random]);
    int slow = start;
    for (int i = start; i <= end; ++i) {
        if (nums[i] < nums[end]) {
            swap(nums[slow], nums[i]);
            ++slow;
        }
    }

    swap(nums[slow], nums[end]);
    return slow;
}

void mergeSort (vector<int>& nums) {
    int n = nums.size();
    vector<int> dst = nums;
    mergehelper(dst, nums, 0, n);
}

void mergehelper (vector<int>& src, vector<int>& dst, int start, int end) {
    if (start + 1 >= end)
        return;
    
    int mid = (start + end) / 2;
    mergehelper(dst, src, start, mid);
    mergehelper(dst, src, mid, end);

    int i = start, j = mid, k = start;
    while (i < mid || j < end) {
        if (j == end || (i < mid && src[i] < src[j])) {
            dst[k++] = src[i++];
        }
        else {
            dst[k++] = src[j++];
        }
    }
}

void bubbleSort (vector<int>& nums) {
    int count = nums.size() - 1;
    while (count) {
        for (int i = 0; i < count; ++i) {
            if (nums[i + 1] < nums[i])
                swap(nums[i + 1], nums[i]);
        }
        --count;
    }
}

void selectionSort (vector<int>& nums) {
    int start = 0;
    int n = nums.size();
    while (start < n) {
        int min_pos = start;
        for (int i = start; i < n; ++i) {
            if (nums[i] < nums[min_pos])
                min_pos = i;
        }
        swap(nums[start], nums[min_pos]);
        ++start;
    }
}

void insertSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        if (j != i - 1)
            nums[j + 1] = key;
    }
}