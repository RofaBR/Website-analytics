#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Visit {
    std::string user_id, product_id, timestamp;
};

std::vector<Visit> readCSV(const std::string& filename) {
    std::vector<Visit> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream lineStream(line);
        Visit visit;

        std::getline(lineStream, visit.user_id, ',');
        std::getline(lineStream, visit.product_id, ',');
        std::getline(lineStream, visit.timestamp, ',');

        data.push_back({ visit });
    }

    file.close();
    return data;
}

int main() {
    std::string filename1 = "day1.csv";
    std::string filename2 = "day2.csv";

    std::vector<Visit> day1_data = readCSV(filename1);
    std::vector<Visit> day2_data = readCSV(filename2);

    std::unordered_map<std::string, std::unordered_set<std::string>> user_to_products_day1;
    std::unordered_map<std::string, std::unordered_set<std::string>> user_to_products_day2;

    for (const auto& visit : day1_data) {
        user_to_products_day1[visit.user_id].insert(visit.product_id);
    }

    for (const auto& visit : day2_data) {
        user_to_products_day2[visit.user_id].insert(visit.product_id);
    }

    std::unordered_set<std::string> both_days_users;
    std::unordered_set<std::string> new_page_users;

    for (const auto& pair : user_to_products_day2) {
        const auto& user_id = pair.first;
        const auto& products_day2 = pair.second;

        if (user_to_products_day1.find(user_id) != user_to_products_day1.end()) {
            both_days_users.insert(user_id);
            const auto& products_day1 = user_to_products_day1[user_id];
            for (const auto& product_id : products_day2) {
                if (products_day1.find(product_id) == products_day1.end()) {
                    new_page_users.insert(user_id);
                    break;
                }
            }
        }
    }

    std::cout << "Users who visited pages on both days:" << std::endl;
    for (const auto& user_id : both_days_users) {
        std::cout << user_id << std::endl;
    }

    std::cout << "\nUsers who visited new pages on the second day:" << std::endl;
    for (const auto& user_id : new_page_users) {
        std::cout << user_id << std::endl;
    }

    return 0;
}
