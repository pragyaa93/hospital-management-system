#include "CSVUtils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

namespace CSV {

    std::vector<std::string> split(const std::string &line, char delimiter) {
        std::vector<std::string> result;
        std::stringstream ss(line);
        std::string item;
        while (std::getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }

    std::string trim(const std::string &s) {
        std::string out = s;
        out.erase(out.begin(), std::find_if(out.begin(), out.end(),
            [](unsigned char ch) { return !std::isspace(ch); }));
        out.erase(std::find_if(out.rbegin(), out.rend(),
            [](unsigned char ch) { return !std::isspace(ch); }).base(), out.end());
        return out;
    }

    std::vector<std::vector<std::string>> readCSV(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot open file: " + filename);

        std::vector<std::vector<std::string>> rows;
        std::string line;
        bool skipHeader = true;

        while (std::getline(file, line)) {
            if (skipHeader) { skipHeader = false; continue; }
            if (line.empty()) continue;
            auto parts = split(line, ',');
            for (auto &p : parts) p = trim(p);
            rows.push_back(parts);
        }
        return rows;
    }

    void writeCSV(const std::string &filename,
                  const std::vector<std::string> &header,
                  const std::vector<std::vector<std::string>> &rows) {
        std::ofstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot write to file: " + filename);

        for (size_t i = 0; i < header.size(); ++i) {
            file << header[i];
            if (i + 1 < header.size()) file << ",";
        }
        file << "\n";

        for (const auto &row : rows) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i + 1 < row.size()) file << ",";
            }
            file << "\n";
        }
    }
}
