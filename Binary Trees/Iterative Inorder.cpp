vector < int > inOrderTrav(node * curr) {
  vector <int> ans;
  stack <node*> s;

  while (true) {
    if (curr != NULL) {
      s.push(curr);
      curr = curr -> left;
    } 
    
    else {
      if (s.empty())    break;
      curr = s.top();
      ans.push_back(curr -> data);
      s.pop();
      curr = curr -> right;
    }
  }
  return ans;
}