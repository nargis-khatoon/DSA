//BRUTEFORCE store node values in array and then check if its vector
//OPTIMAL- find middle of linked list. reverse from the next node of middle node and compare first node with reversed node.
//OPTIMAL 2 USE STACK LIFO and compare
    bool isPalindrome(ListNode* head) {
        stack<int> sck;
        vector<int> vct;
        ListNode* curr = head;

        //Push all the nodes into a stack and vector
        while(curr != nullptr){
            sck.push(curr->val);
            vct.push_back(curr->val);

            curr = curr->next;
        }

        //Criss-Cross comparison of the values. So the beginning of the vector is compared to the top of the stack
        for(int i = 0; i < vct.size(); i++){
            if(vct[i] != sck.top()){
                return false;
            }
            sck.pop();
        }

        return true;
    }