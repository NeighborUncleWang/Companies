#include <iostream>
#include <vector>

using namespace std;


struct QuadTreeNode {
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;
    int min = INT_MAX;
    vector<QuadTreeNode*> children = vector<QuadTreeNode*>(4, nullptr);
    QuadTreeNode(int row1, int col1, int row2, int col2, int min) {
        this->row1 = row1;
        this->row2 = row2;
        this->col1 = col1;
        this->col2 = col2;
        this->min = min;
    }
};
class NumMatrix {
private:
    QuadTreeNode* root;
    QuadTreeNode* BuildQuadTree(vector<vector<int>>& matrix,
                                int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) {
            return nullptr;
        } else if (row1 == row2 && col1 == col2) {
            return new QuadTreeNode(row1, col1, row2, col2, matrix[row1][col1]);
        }
        QuadTreeNode* node = new QuadTreeNode(row1, col1, row2, col2, INT_MAX);
        int middleRow = row1 + (row2 - row1) / 2;
        int middleColumn = col1 + (col2 - col1) / 2;
        node->children[0] = BuildQuadTree(matrix, row1, col1, middleRow, middleColumn);
        node->children[1] = BuildQuadTree(matrix, row1, middleColumn + 1, middleRow, col2);
        node->children[2] = BuildQuadTree(matrix, middleRow + 1, col1, row2, middleColumn);
        node->children[3] = BuildQuadTree(matrix, middleRow + 1, middleColumn + 1, row2, col2);
        for (auto child : node->children) {
            if (child != nullptr) {
                node->min = min(child->min, node->min);
            }
        }
        return node;
    }
    void updateHelper(QuadTreeNode* node, int row, int col, int val) {
        if (node == nullptr || row < node->row1 || row > node->row2
            || col < node->col1 || col > node->col2) {
            return;
        } else if (row == node->row1 && node->row1 == node->row2
                   && col == node->col1 && node->col1 == node->col2) {
            node->min = val;
            return;
        }
        for (QuadTreeNode* child : node->children) {
            updateHelper(child, row, col, val);
        }
        node->min = INT_MAX;
        for (QuadTreeNode* child : node->children) {
            if (child) {
                node->min = min(child->min, node->min);
            }
        }
    }
    int minRegionHelper(QuadTreeNode* node, int row1, int col1, int row2, int col2) {
        if (node == nullptr || node->row1 > row2 || node->col1 > col2
            || node->row2 < row1 || node->col2 < col1) {
            return INT_MAX;
        } else if (node->row1 >= row1 && node->col1 >= col1
                   && node->row2 <= row2 && node->col2 <= col2) {
            return node->min;
        }
        int result = INT_MAX;
        for (auto child : node->children) {
            result = min(result, minRegionHelper(child, row1, col1, row2, col2));
        }
        return result;
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        root = BuildQuadTree(matrix, 0, 0, rowSize - 1, columnSize - 1);
    }

    void update(int row, int col, int val) {
        updateHelper(root, row, col, val);
    }

    int minRegion(int row1, int col1, int row2, int col2) {
        return minRegionHelper(root, row1, col1, row2, col2);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);



struct SegmentTreeNode {
    int start = 0;
    int end = 0;
    int min = 0;
    SegmentTreeNode* left = nullptr;
    SegmentTreeNode* right = nullptr;
    SegmentTreeNode(int start, int end, int min) {
        this->start = start;
        this->end = end;
        this->min = min;
    }
};
class NumArray {
private:
    SegmentTreeNode* root;
    int size;
    SegmentTreeNode* constructTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        }
        int middle = start + (end - start) / 2;
        SegmentTreeNode* current = new SegmentTreeNode(start, end, 0);
        current->left = constructTree(nums, start, middle);
        current->right = constructTree(nums, middle + 1, end);
        current->min = min(current->left->min, current->right->min);
        return current;
    }
    void updateTree(SegmentTreeNode* current, int index, int val) {
        if (current->start == index && current->end == index) {
            current->min = val;
            return;
        } else if (current->start > index || current->end < index) {
            return;
        }
        updateTree(current->left, index, val);
        updateTree(current->right, index, val);
        current->min = min(current->left->min, current->right->min);
    }
    int minQuery(SegmentTreeNode* current, int start, int end) {
        if (current->start >= start && current->end <= end) {
            return current->min;
        } else if (current->end < start || current->start > end) {
            return INT_MAX;
        }
        return min(minQuery(current->left, start, end), minQuery(current->right, start, end));
    }
public:
    NumArray(vector<int> &nums) {
        size = nums.size();
        root = constructTree(nums, 0, size - 1);
    }

    void update(int i, int val) {
        updateTree(root, i, val);
    }

    int minRange(int i, int j) {
        return minQuery(root, i, j);
    }
};


int main() {
    vector<int> nums{2,-10,-8,-6,8,6,4,0,-4,-2};
    NumArray a(nums);
    cout << "RMQ(0,1), -10 = " << a.minRange(0,1) << endl;
    cout << "RMQ(2,3), -8 = " << a.minRange(2,3) << endl;
    cout << "RMQ(4,7), 0 = " << a.minRange(4,7) << endl;

    vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    NumMatrix s(matrix);
    cout << "RMQ((0,0),(2,2)) 1 = " << s.minRegion(0,0,2,2) << endl;
    cout << "RMQ((1,1),(2,2)) 5 = " << s.minRegion(1,1,2,2) << endl;
    cout << "RMQ((2,2),(2,2)) 9 = " << s.minRegion(2,2,2,2) << endl;
    return 0;
}