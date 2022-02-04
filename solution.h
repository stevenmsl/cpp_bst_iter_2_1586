
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <stack>
using namespace std;
namespace sol1586
{
    class BTSIterator
    {
    private:
        /* traverse the tree */
        stack<Node *> t;
        /*
          - the state which store the node
            from small to big in value
        */
        vector<Node *> state;
        int pos = -1;
        void fetchNodes(Node *node);
        bool available(int index);

    public:
        BTSIterator(Node *tree);
        bool hasNext();
        int next();
        bool hasPrev();
        int prev();
    };
}
#endif