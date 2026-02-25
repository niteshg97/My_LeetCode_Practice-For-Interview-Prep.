class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // base case 
    if(p==NULL & q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    
    if(p->val != q-> val) return false;  // root node compare 

    bool leftSide=isSameTree(p->left,q->left);  // recurssion 
    if(leftSide==false) return false ;
      
    bool rightSide=isSameTree(p->right,q->right); // recurssion
    if(rightSide==false) return false;

    return true;


    


  }
};
