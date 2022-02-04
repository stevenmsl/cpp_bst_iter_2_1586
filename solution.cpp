#include "solution.h"

#include <functional>
#include <unordered_map>
#include <stack>
using namespace sol1586;
using namespace std;

/* takeaways
   - use stack to perform inorder traversal
   - traverse the tree piece by piece depending
     on if the next element is the last element
     in the state
   - state itself is a vector and will grow
     dynamically everytime we fetch more nodes
*/

BTSIterator::BTSIterator(Node *tree)
{
  /* need to get things going  */
  fetchNodes(tree);
}

/*
  - fetch the nodes on-demand
*/
void BTSIterator::fetchNodes(Node *node)
{
  /* smallest number on top of the stack */
  while (node != nullptr)
  {
    t.push(node);
    node = node->left;
  }
}

bool BTSIterator::available(int pos)
{
  return pos >= 0 && pos < state.size();
}

bool BTSIterator::hasNext()
{
  /*
    - we are good if we are not currently
      at the very last element of the state
  */

  if (available(pos + 1))
    return true;

  /*
    - if we are, we check if there
      are more nodes we can pull in to
      augment the state
  */
  return !t.empty();
}

/* this is the key
   - if we are about to run out of
     elements, we fetch more nodes
     to grow the state until we
     finished traversing the tree
   - by about to run out it means the
     pos is already pointing at
     the second to the last element
     in the state
*/
int BTSIterator::next()
{
  int nextVal = INT_MIN;
  /*
    - if the next pos is not the last elemet
  */
  if (available(pos + 1))
    nextVal = state[pos + 1]->val;
  /*
    - the next is the very last one in
      the state
    - we need to fetch more if there are
      still more to fetch
  */
  else if (!t.empty())
  {
    auto node = t.top();
    /* you need to pop it right away
       as there are more coming once
       you fetched more nodes to
       the stack
    */
    t.pop();
    fetchNodes(node->right);
    /* add  to the state */
    state.push_back(node);
    /* node as done its job to
       - fetch nodes
       - agument the state
    */
    nextVal = node->val;
  }
  pos++;

  return nextVal;
}

bool BTSIterator::hasPrev()
{
  return available(pos - 1);
}
int BTSIterator::prev()
{
  int prevVal = INT_MIN;
  if (available(pos - 1))
  {
    prevVal = state[--pos]->val;
  }

  return prevVal;
}
