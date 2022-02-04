#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol1586
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int val) : val(val), left(nullptr), right(nullptr) {}
    };
}
#endif