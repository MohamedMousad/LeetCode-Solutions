class FoodRatings {
public:
    unordered_map<string ,pair<string , int>> data;
    unordered_map<string , map<int,  set<string>>> cuisine_ratings;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0 ; i < foods.size() ; i++){
            data[foods[i]] = { cuisines[i] , ratings[i]};
            cuisine_ratings[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto curr = data.find(food);
        auto [ cuisine , old_rate ] = curr->second;
        curr->second = { cuisine ,newRating};

        cuisine_ratings[cuisine][old_rate].erase(food);
        if(cuisine_ratings[cuisine][old_rate].empty()) {
            cuisine_ratings[cuisine].erase(old_rate);
        }

        cuisine_ratings[cuisine][newRating].insert(food);
    }
    string highestRated(string cuisine) {
        return *cuisine_ratings[cuisine].rbegin()->second.begin();
    }
};