//{ Driver Code Starts
// Initial Template for C++
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseList(struct Node* head) 
    {
        vector<int>Reverse;
        
        Node* temp=head;
        while(temp!=NULL)
        {
            Reverse.push_back(temp->data);
            temp=temp->next;
        }
        
        reverse(Reverse.begin(),Reverse.end());
        
        Node *newnode=new Node(Reverse[0]);
        temp=newnode;
        for(int i=1;i<Reverse.size();i++)
        {
            Node *node=new Node(Reverse[i]);
            temp->next=node;
            temp=temp->next;
        }
        
        return newnode;
    }
};