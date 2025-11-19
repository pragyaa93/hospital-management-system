#pragma once
#include <string>
#include <vector>

namespace CSV {

    // Split a string by delimiter. Handles simple quoted fields (e.g. "a, b",c).
    std::vector<std::string> split(const std::string &line, char delimiter);

    // Trim whitespace around string
    std::string trim(const std::string &s);

    // Read all rows from a CSV file (skips header)
    std::vector<std::vector<std::string>> readCSV(const std::string &filename);

    // Write CSV (overwrite)
    void writeCSV(const std::string &filename,
                  const std::vector<std::string> &header,
                  const std::vector<std::vector<std::string>> &rows);
}
