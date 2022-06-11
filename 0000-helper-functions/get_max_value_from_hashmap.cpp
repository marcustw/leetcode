static bool compare(const pair<int,int>&a, const pair<int,int>&b) {
   return a.second<b.second;
}

int get_max_value_from_hashmap(unordered_map<int,int>& m) {
    return max_element(m.begin(), m.end(), compare)->second;
}
