class MovieRentingSystem {
private:
    map<int, set<pair<int,int>>> available_movies;   // movie -> available (price, shop)
    map<pair<int,int>, int> movie_price;             // (movie, shop) -> price
    set<tuple<int,int,int>> rented_set;              // rented movies: (price, shop, movie)

public:
    MovieRentingSystem(int n, vector<vector<int>>& inventory) {
        for (auto &entry : inventory) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            available_movies[movie].insert({price, shop});
            movie_price[{movie, shop}] = price; 
        }
    }

    vector<int> search(int movie) {
        vector<int> top_shops;
        if (available_movies.find(movie) == available_movies.end()) return top_shops;

        for (auto &[price, shop] : available_movies[movie]) {
            top_shops.push_back(shop);
            if (top_shops.size() == 5) break;
        }
        return top_shops;
    }

    void rent(int shop, int movie) {
        int price = movie_price[{movie, shop}];
        rented_set.insert({price, shop, movie});
        available_movies[movie].erase({price, shop});
    }

    void drop(int shop, int movie) {
        int price = movie_price[{movie, shop}];
        rented_set.erase({price, shop, movie});
        available_movies[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> top_rented;
        for (auto &[price, shop, movie] : rented_set) {
            top_rented.push_back({shop, movie});
            if (top_rented.size() == 5) break;
        }
        return top_rented;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */