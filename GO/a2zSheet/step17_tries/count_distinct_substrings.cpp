struct Node{
    Node* links[26];
};

int countDistinctSubstrings(string &s)
{   int n = s.size();
    Node* root = new Node();
    int cnt = 0;
    for(int i=0;i<n;i++){
        Node* temp = root;
        for(int j = i;j<n;j++){
            if(!temp->links[s[j]-'a']){
                cnt++;
                temp->links[s[j]-'a'] = new Node();
            }
            temp = temp->links[s[j]-'a'];
        }
    }

    return cnt+1;
}