vector < int > preOrderTrav(node * curr) {
  vector < int > ans;
  if (curr == NULL)
    return preOrder;

  stack < node * > s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    ans.push_back(topNode -> val);
    s.pop();

    if (topNode -> right != NULL)   s.push(topNode -> right);
    if (topNode -> left != NULL)    s.push(topNode -> left);
  }
  return preOrder;
}