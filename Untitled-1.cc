#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){}
};

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}

    void traversal(TreeNode* cur,vector<int> & vec){
        if(cur==NULL)return;
        vec.push_back(cur->val);
        preorderTraversal(cur->left);
        preorderTraversal(cur->right);

    }

    vector<int> preorderTraversal(TreeNode *root){
        vector<int> vec;
        traversal(root,vec);
        return vec;
    }
};
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index=s.size()-1;
        int result=0;
        for(int i=g.size()-1;i>=0;i--){
            if(index>=0&&s[index]>=g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
};


int main(){

    Solution so;
    vector<int> g={1,2,3};
    vector<int> s={1,1};
    cout<<so.findContentChildren(g,s)<<endl;
    return 0;

}

