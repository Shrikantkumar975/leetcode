class WordDictionary {
public:
    struct trieNode{
        bool endOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->endOfWord=false;

        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }

        return newNode;
    }
    trieNode* root;
    WordDictionary() {   
        root = getNode();
    }
    
    void addWord(string word) {
        trieNode* crawler = root;

        for(char ch: word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }

        crawler->endOfWord = true;
    }

    bool searchUtil(trieNode* root,string word){
        trieNode* crawler = root;

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->children[j]!=NULL){
                        if(searchUtil(crawler->children[j],word.substr(i+1)))
                            return true;
                    }
                }

                return false;
            }else if( crawler->children[ch-'a']==NULL){
                return false;
            }

            crawler = crawler->children[ch-'a'];
        }

        return (crawler!=NULL && crawler->endOfWord);
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */