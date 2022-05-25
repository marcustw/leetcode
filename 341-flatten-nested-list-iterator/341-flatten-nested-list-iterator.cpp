/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> arr;
    int index=0;
    
    vector<int> flatten(NestedInteger nestedInt) {
        vector<int> res;
        if (nestedInt.isInteger()) {
            res.push_back(nestedInt.getInteger());
        } else {
            vector<NestedInteger>& ls = nestedInt.getList();
            for (NestedInteger ni : ls) {
                vector<int> flattened = flatten(ni);
                res.insert(end(res), begin(flattened), end(flattened));
            }
        }
        return res;        
    }
public:
    // NestedInteger is either integer or vector<NestedInteger>
    // isInteger()
    // getInteger()
    // getList()
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger ni : nestedList) {
            vector<int> flattened = flatten(ni);
            arr.insert(end(arr), begin(flattened), end(flattened));
        }
    }
    
    int next() {
        return arr[index++];
    }
    
    bool hasNext() {
        return index!=arr.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */