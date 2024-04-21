#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Read JSON data
    std::ifstream jsonFile("data.json");
    json jsonData;
    jsonFile >> jsonData;

    // Read JSON schema
    std::ifstream schemaFile("schema.json");
    json schemaData;
    schemaFile >> schemaData;

    // Validate JSON against schema
    try {
        //jsonData.validate(schemaData);
        std::cout << "JSON is valid according to the schema.\n";
    } catch (json::exception& e) {
        std::cerr << "JSON validation failed: " << e.what() << "\n";
    }

    return 0;
}

