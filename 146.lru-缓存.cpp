/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    // 进出的顺序
    std::list<std::pair<int,int>> m_list;
    std::map<int,decltype(m_list.begin())> m_map;
    int m_capacity;

    // 1.get page
    void getRecentlyPage(int key){
        auto it = m_map.find(key);
        // it.second == m_map[key];
        if(it != m_map.end()){
            // auto temp_it = m_list.insert(m_list.end(),std::make_pair(key,it->second->second));
            auto temp_it = m_list.insert(m_list.end(),it->second);
            m_list.erase(it->second);
            m_map[key] = temp_it; 
        }
    }

    //2. delete 
    void deleteOldestPage(){
        m_map.erase(m_list.begin()->first);
        m_list.pop_front();
    }

    //3. update
    void update(int key , int value){
        m_map[key]->second = value;
        getRecentlyPage(key);
    }

    // 4. addNewPage
    void addNewPage(int key, int value){
        auto it = m_list.insert(m_list.end(),std::make_pair(key,value));
        m_map[key] = it;
    }
public:
    LRUCache(int capacity) : m_capacity(capacity){

    }
    
    int get(int key) {
        auto it = m_map.find(key);
        if(it != m_map.end()){
            getRecentlyPage(key);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m_map.find(key) == m_map.end()){
            if(m_list.size() == m_capacity){
                deleteOldestPage();
            }
            addNewPage(key, value);
        }else{
            update(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

