//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	struct TreeNode* result = NULL;
    if(t1!=NULL&&t2!=NULL){
    	result= (struct TreeNode *)malloc(sizeof(struct TreeNode));
    	result->val = t1->val+t2->val;
    	result->left = mergeTrees(t1->left,t2->left);
   		result->right = mergeTrees(t1->right,t2->right);
    }else if(t1!=NULL){
    	result= (struct TreeNode *)malloc(sizeof(struct TreeNode));
    	result->val = t1->val;
    	result->left = mergeTrees(t1->left,t2);
   		result->right = mergeTrees(t1->right,t2);
    }else if(t2!=NULL){
    	result= (struct TreeNode *)malloc(sizeof(struct TreeNode));
    	result->val = t2->val;
    	result->left = mergeTrees(t1,t2->left);
   		result->right = mergeTrees(t1,t2->right);
    }else{
    }
    return result;
}