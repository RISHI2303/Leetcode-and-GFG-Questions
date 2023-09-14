class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::vector<std::string>> graph;
        
        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto& [_, dests] : graph) {
            std::sort(dests.rbegin(), dests.rend());
        }
        
        std::vector<std::string> stack = {"JFK"};
        std::vector<std::string> itinerary;
        
        while (!stack.empty()) {
            std::string curr = stack.back();
            if (graph.find(curr) != graph.end() && !graph[curr].empty()) {
                stack.push_back(graph[curr].back());
                graph[curr].pop_back();
            } else {
                itinerary.push_back(stack.back());
                stack.pop_back();
            }
        }
        
        std::reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};