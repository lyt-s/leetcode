class LRUCache {
private:

    list<pair<int,int>> list_;
    map<int,decltype(list_.begin())> mp;
    int capacity_;

    // 得到最近
    void makeRecently(int key){
        auto temp_it = list_.insert(list_.end(),*mp[key]);
        list_.erase(mp[key]);
        mp[key] = temp_it;
    }

    void addPoint(int key ,int value){
        auto temp_it = list_.insert(list_.end(),{key,value});
        mp.emplace(std::make_pair(key,temp_it));
    }

    void deltetOldest(){
        mp.erase(list_.begin()->first);
        list_.pop_front();
    }

    void updateValue(int key,int value){
        mp[key]->second = value;
        makeRecently(key);
    }
public:

    LRUCache(int capacity) :capacity_(capacity) {

    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            makeRecently(key);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){ // 没找到
            if(list_.size() == capacity_){ // 满了
                deltetOldest(); // 删掉最老节点
            }
            addPoint(key, value); // 添加新节点
        }else{ // 找到了
            updateValue(key, value); // 更新节点值
        }

    }
};

class LRUCache {
private:

    list<pair<int,int>> m_list;  // [key,value]
    map<int,decltype<m_list.begin()> m_map; // [key, iterator]
    int m_capacity;

    void update(int key, int value){
        
    }

    void addNewPoint(int key, int value){

    }
public:

    LRUCache(int capacity) :m_capacity(capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {


    }
};