/*中序遍历*/
vector <int> InorderTraversal(TreeNode *root)
{
  vector<int> result;
  
  //使用堆栈来完成
  stack <TreeNode *> my_stack;
  
  //先把根节点加入到栈里
  if (root != NULL) my_stack.push(root);
  
  while(!my_stack.empty())
  {
    //分两种情况 先取栈顶元素 
    TreeNode *node = my_stack.top();
    
    //1.栈顶不是NULL
    if(node != NULL)
    {
      my_stack.pop(); // 先弹出去  再加入 右 中 左 元素 顺序很重要
      if(node->right) my_stack.push(node->right);
                      my_stack.push(node); my_stack.push(NULL); //加入 中 的时候，这里两句话绑定，NULL作为标记
      if(node->left) my_stack.push(node->left);
    }
    
    //2.栈顶是NULL
    else
    {
      my_stak.pop(); //把NULL先弹出
      node = my_stack.top();
      result.push_back(node->val); // 加入到结果集
      my_stack.pop();
    }
  }
  return result;
}





/*前序遍历（中左右）

三句话调换位置 右 左 中
*/ 
 if(node->right) my_stack.push(node->right);
                     
 if(node->left) my_stack.push(node->left);

                my_stack.push(node); my_stack.push(NULL); //加入 中 的时候，这里两句话绑定，NULL作为标记





/*后续遍历  左 右 中
三句话调换位置  中 右 左
*/
my_stack.push(node); my_stack.push(NULL); //加入 中 的时候，这里两句话绑定，NULL作为标记
 
                    if(node->right) my_stack.push(node->right);
                     
                    if(node->left) my_stack.push(node->left);
