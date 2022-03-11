#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 计数排序
void countSort (vector<int>& nums);
// 快速排序
int partition (vector<int>& nums, int start, int end); 
void quickSort (vector<int>& nums, int start, int end);
// 归并排序
void mergeSort (vector<int>& nums);
void mergehelper (vector<int>& src, vector<int>& dst, int start, int end);
// 冒泡排序
void bubbleSort (vector<int>& nums);
// 选择排序
void selectionSort (vector<int>& nums);
// 插入排序
void insertSort(vector<int>& nums);
// 桶排序
void Bucket_sort(vector<int>& nums, int bucketSize);
// 堆排序
void Heapsort(vector<int>& nums);
void buildheap(vector<int>& temp, int cur);
void deleteheap(vector<int>& temp, int cur);

int main() {
    vector<int> nums = {2, 3, 4, 2, 3, 2, 1};
    insertSort(nums);
    // selectionSort(nums);
    // bubbleSort(nums);
    // countSort(nums);
    // quickSort(nums, 0, nums.size() - 1);
    // mergeSort(nums);
    // Bucket_sort(nums, 2);
    // Heapsort(nums);
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

void Bucket_sort(vector<int>& nums, int bucketSize) {
    int n = nums.size();
    int min_num = nums[0];
    int max_num = nums[0];
    // 找出最大值和最小值
    for (int i = 0; i < n; ++i) {
        min_num = min(min_num, nums[i]);
        max_num = max(max_num, nums[i]);
    }
    // 根据每个桶的数量计算需要的桶的数量
    int bucketCount = (max_num - min_num) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);
    for (int i = 0; i < n; ++i) {
        int pos = (nums[i] - min_num) / bucketSize;
        buckets[pos].emplace_back(nums[i]);
    }
    // 对每个桶单独进行排序，可以选择其他排序方法，这里直接使用自带的sort 
    int count = 0;
    for (int i = 0; i < bucketCount; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
        
        for (int j = 0; j < bucketSize; ++j) 
            nums[count++] = buckets[i][j];
    }
}

void Heapsort(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp = nums;

    for (int i = 0; i < n; ++i)
        buildheap(temp, i);
    
    for (int i = 0; i < n; ++i)
        cout << temp[i] << ' ';

    int count = 0;
    for (int i = n - 1; i >= 0; --i) {
        nums[count++] = temp[0];
        deleteheap(temp, i);
    }
}

void buildheap(vector<int>& temp, int cur) {
    int parent = (cur - 1) / 2;
    while (temp[parent] > temp[cur]) {
        swap(temp[parent], temp[cur]);
        cur = parent;
        parent = (parent - 1) / 2;
    }
}

void deleteheap(vector<int>& temp, int cur) {
    swap(temp[0], temp[cur]);
    int k = 0;
    while (k < cur) {
        int lhs = k * 2 + 1;
        int rhs = k * 2 + 2;
        
        if (lhs >= cur)
            break;
        
        else if (rhs < cur) {
            if (temp[k] <= min(temp[lhs], temp[rhs]))
                break;
            
            else if (temp[lhs] < temp[rhs]) {
                swap(temp[k], temp[lhs]);
                k = lhs;
            }
            else {
                swap(temp[k], temp[rhs]);
                k = rhs;                
            }
        }

        else if (lhs < cur && rhs >= cur) {
            if (temp[k] > temp[lhs]) {
                swap(temp[k], temp[lhs]);
                k = lhs;                
            }
            else
                break;
        }
    }
}
