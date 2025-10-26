// ProjectTwo.cpp
// CS 300 - Advising Assistance Program
// Single-file C++ solution (no external headers).
// Reads a CSV of courses, stores in a map, prints sorted lists and course info.
//
// Build: g++ -std=c++17 ProjectTwo.cpp -o project_two
// Run:   ./project_two
//
// CSV format (example line):
// CSCI300,Introduction to Algorithms,CSCI200,MATH201
//
// Author: (replace with your name)
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

struct Course {
    std::string number;                     // e.g., CSCI200
    std::string title;                      // e.g., Data Structures
    std::vector<std::string> prereq_nums;   // e.g., {"CSCI101","MATH201"}
};

// ===== Utility helpers =====
static inline std::string ltrim(std::string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch){ return !std::isspace(ch); }));
    return s;
}
static inline std::string rtrim(std::string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch){ return !std::isspace(ch); }).base(), s.end());
    return s;
}
static inline std::string trim(std::string s) { return rtrim(ltrim(s)); }

static inline std::string toUpper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
    return s;
}

// Split a CSV line into fields (simple CSV without quoted commas)
static std::vector<std::string> splitCSV(const std::string& line) {
    std::vector<std::string> out;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) {
        out.push_back(trim(item));
    }
    // If trailing comma, getline will not add empty field; not expected in this dataset.
    return out;
}

// ===== Core catalog data structure =====
class Catalog {
public:
    // Load from CSV file. Returns true on success.
    bool loadFromFile(const std::string& filename, std::string& errMsg) {
        std::ifstream in(filename);
        if (!in.is_open()) {
            errMsg = "Error: could not open file '" + filename + "'.";
            return false;
        }
        std::string line;
        size_t lineNo = 0;
        std::map<std::string, Course> temp; // build first, then swap in on success

        while (std::getline(in, line)) {
            ++lineNo;
            // skip blank lines
            if (trim(line).empty()) continue;
            auto fields = splitCSV(line);
            if (fields.size() < 2) {
                errMsg = "Parse error on line " + std::to_string(lineNo) + ": expected at least 2 fields.";
                return false;
            }
            Course c;
            c.number = toUpper(fields[0]);
            c.title  = fields[1];
            for (size_t i = 2; i < fields.size(); ++i) {
                if (!fields[i].empty()) c.prereq_nums.push_back(toUpper(fields[i]));
            }
            temp[c.number] = std::move(c);
        }

        courses.swap(temp);
        return true;
    }

    bool empty() const { return courses.empty(); }

    // Get a sorted list of course numbers (alphanumeric ascending)
    std::vector<std::string> sortedCourseNumbers() const {
        std::vector<std::string> keys;
        keys.reserve(courses.size());
        for (const auto& kv : courses) keys.push_back(kv.first);
        std::sort(keys.begin(), keys.end(), [](const std::string& a, const std::string& b){
            // Case-insensitive lexicographic compare (numbers sort naturally as substrings)
            std::string A = toUpper(a), B = toUpper(b);
            return A < B;
        });
        return keys;
    }

    // Print a single course line: "CSCI200, Data Structures"
    void printCourseLine(const std::string& number) const {
        auto it = courses.find(number);
        if (it == courses.end()) return;
        std::cout << it->second.number << ", " << it->second.title << "\n";
    }

    // Print detailed course information: title and prerequisites (numbers and titles if available)
    void printCourseDetail(const std::string& number) const {
        auto it = courses.find(number);
        if (it == courses.end()) {
            std::cout << "Course '" << number << "' was not found.\n";
            return;
        }
        const Course& c = it->second;
        std::cout << c.number << ", " << c.title << "\n";
        if (c.prereq_nums.empty()) {
            std::cout << "Prerequisites: None\n";
        } else {
            std::cout << "Prerequisites: ";
            for (size_t i = 0; i < c.prereq_nums.size(); ++i) {
                const std::string& p = c.prereq_nums[i];
                auto pit = courses.find(p);
                if (pit != courses.end()) {
                    std::cout << p << " (" << pit->second.title << ")";
                } else {
                    std::cout << p << " (not found)";
                }
                if (i + 1 < c.prereq_nums.size()) std::cout << ", ";
            }
            std::cout << "\n";
        }
    }

private:
    std::map<std::string, Course> courses; // keyed by course number (uppercased)
};

// ===== Menu UI =====
void printMenu() {
    std::cout << "\n1. Load Data Structure.\n";
    std::cout << "2. Print Course List.\n";
    std::cout << "3. Print Course.\n";
    std::cout << "9. Exit\n\n";
    std::cout << "What would you like to do? ";
}

int main() {
    std::cout << "Welcome to the course planner.\n\n";

    Catalog catalog;
    bool loaded = false;

    while (true) {
        printMenu();
        std::string choice;
        if (!std::getline(std::cin, choice)) break;
        choice = trim(choice);
        if (choice.empty()) continue;

        if (choice == "1") {
            std::cout << "Enter the file name to load (e.g., ABCU_Advising_Program_Input.csv): ";
            std::string filename;
            std::getline(std::cin, filename);
            filename = trim(filename);
            if (filename.empty()) {
                std::cout << "No file name provided.\n";
                continue;
            }
            std::string err;
            if (catalog.loadFromFile(filename, err)) {
                loaded = true;
                std::cout << "Data loaded successfully from '" << filename << "'. ("
                          << "courses: " << catalog.sortedCourseNumbers().size() << ")\n";
            } else {
                std::cout << err << "\n";
                loaded = false;
            }
        }
        else if (choice == "2") {
            if (!loaded) {
                std::cout << "Please load the data structure first (option 1).\n";
                continue;
            }
            std::cout << "\nHere is a sample schedule:\n\n";
            auto keys = catalog.sortedCourseNumbers();
            for (const auto& num : keys) {
                catalog.printCourseLine(num);
                std::cout << "\n";
            }
        }
        else if (choice == "3") {
            if (!loaded) {
                std::cout << "Please load the data structure first (option 1).\n";
                continue;
            }
            std::cout << "What course do you want to know about? ";
            std::string q;
            std::getline(std::cin, q);
            q = toUpper(trim(q));
            if (q.empty()) {
                std::cout << "No course entered.\n";
                continue;
            }
            catalog.printCourseDetail(q);
        }
        else if (choice == "9") {
            std::cout << "Thank you for using the course planner!\n";
            break;
        }
        else {
            std::cout << choice << " is not a valid option.\n";
        }
    }
    return 0;
}
