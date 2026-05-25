class LockingTree {
public:
    int n;
    vector<int> parent;
    vector<int> isLocked;
    vector<int> lockedBy;
    vector<vector<int>> child;
    LockingTree(vector<int>& parent) {
        this->parent=parent;
        n=parent.size();
        isLocked.resize(n, 0); 
        lockedBy.resize(n, -1);
        child.resize(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(!isLocked[num]){
            isLocked[num]=1;
            lockedBy[num]=user;
            return true;
        }

        return false;
    }
    
    bool unlock(int num, int user) {
        if(isLocked[num] && lockedBy[num]==user){
            isLocked[num]=0;
            lockedBy[num]=-1;
            return true;
        }

        return false;
    }

    void checkDecendentLocked(int num,vector<int> &locked){
        queue<int> q;
        q.push(num);
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(isLocked[curr]){
                locked.push_back(curr);
            }

            for(int &a: child[curr]){
                q.push(a);
            }
        }
    }

    bool checkAncestorLocked(int num){
        while(num!=-1){
            if(isLocked[num]) return true;

            num=parent[num];
        }

        return false;
    }
    
    bool upgrade(int num, int user) {
        if(isLocked[num]) return false;
        vector<int> locked;
        checkDecendentLocked(num,locked);
        if(locked.size()==0) return false;

        if(checkAncestorLocked(parent[num])) return false;

        for(int &a: locked){
            isLocked[a]=0;
            lockedBy[a]=-1;
        }
        isLocked[num]=1;
        lockedBy[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */