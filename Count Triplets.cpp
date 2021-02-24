int find_pair(vector<int> &arr, int low, int high, int val) {
    int count = 0;
    while(low < high) {
        int pair_sum = (arr[low]+arr[high]);
        if(pair_sum == val) {
            count++;
            low++;
            high--;
        } else if(pair_sum > val) {
            high--;
        } else {
            low++;
        }
    }
    return count;
}
int countTriplets(struct Node* head, int x) { 
    vector<int> vec;
    Node * node=head;
    
    while(node != NULL){
        vec.push_back(node->data);
        node = node->next;
    }
    if(vec.size() < 3) {
        return -1;
    }
    
    int count = 0;
    for(int i=0; i<vec.size()-2; ++i) {
        count += find_pair(vec, i+1, vec.size()-1, x-vec[i]);
    }
    return count;
} 