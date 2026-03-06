#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <iostream>
#include "fn/print_content.h"

constexpr size_t NAME_LENGTH_RESERVE = 20;
constexpr size_t NAME_LEFT_PART = 8;
constexpr size_t NAME_RIGHT_PART = 8;

constexpr size_t DATE_LENGTH_RESERVE = 10;
constexpr size_t SIZE_LENGTH_RESERVE = 3;

static std::string get_human_size(uintmax_t size) {
    const std::vector<std::string> units =
    { "B", "KB", "MB", "GB", "TB", "PB" };

    double step = 1024.9;

    double value = size;
    size_t unit = 0;

    while (value >= step && unit < units.size() - 1) {
        value /= step;
        unit++;
    }

    char buffer[64];

    if (value >= 100)
        snprintf(buffer, sizeof(buffer), "%.0f %s", value, units[unit].c_str());
    else if (value >= 10)
        snprintf(buffer, sizeof(buffer), "%.1f %s", value, units[unit].c_str());
    else
        snprintf(buffer, sizeof(buffer), "%.2f %s", value, units[unit].c_str());

    return buffer;
}

static std::string shorten_name(const std::string& str) {
    if (str.length() <= NAME_LENGTH_RESERVE)
        return str;

    std::string ext;
    std::string name_part;

    auto dotPos = str.find_last_of('.');
    if (dotPos != std::string::npos) {
        name_part = str.substr(0, dotPos);
        ext = str.substr(dotPos);
    }
    else {
        name_part = str;
    }

    size_t left = NAME_LEFT_PART;
    size_t right = NAME_RIGHT_PART;

    if (name_part.length() < left)
        left = name_part.length();

    if (ext.length() < right)
        right = ext.length();

    std::string result;

    result += name_part.substr(0, left);
    result += "...";

    if (ext.length() > right)
        result += ext.substr(ext.length() - right);
    else
        result += ext;

    return result;
}

static std::string format_time(std::filesystem::file_time_type ftime) {
    auto sctp = std::chrono::time_point_cast<
        std::chrono::system_clock::duration>(
            ftime - std::filesystem::file_time_type::clock::now()
            + std::chrono::system_clock::now());

    std::time_t ctime = std::chrono::system_clock::to_time_t(sctp);

    std::tm tm = *std::localtime(&ctime);

    char buf[64];
    strftime(buf, sizeof(buf), "%m/%d/%Y", &tm);

    return buf;
}

void fn::print_content(std::vector<Item> content) {

    std::string out;
    out.reserve(((uintmax_t)content.size()) * 
        (NAME_LENGTH_RESERVE 
        + DATE_LENGTH_RESERVE 
        + SIZE_LENGTH_RESERVE));

    for (auto& item : content) {

        std::string name = item.filename().u8string();
        if (name.length() > NAME_LENGTH_RESERVE)
            name = shorten_name(name);

        char* prefix = ". ";

        if (item.type() == ItemType::directory) {
            prefix = "] ";
        }
        
        name = prefix + name;

        std::string size = item.size() < 1
            ? "0 B"
            : get_human_size(item.size());

        std::string date = format_time(
            std::filesystem::last_write_time(item.path())
        );

        char line[256];

        snprintf(line, sizeof(line),
            "%-23s %s   %s\n",
            name.c_str(),
            date.c_str(),
            size.c_str()
        );
        
        out += line;
    }

    std::cout << out;
}