#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
class User {
public:
    std::string _name;
    std::string _login;
    std::string _pass;

    void loadFromFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cout << "Couldn't open the file for reading: " << filename << std::endl;
            return;
        }
        std::string line;

        while (std::getline(infile, line)) {
            std::cout << line<<" ";
        }
        std::cout << "\n";
        
    }

    void saveToFile(const std::string& filename) {
        std::ofstream outfile(filename);
        if (!outfile) {
            std::cout << "Couldn't open the file for writing: " << filename << std::endl;
            return;
        }
        outfile << _name << "\n" << _login << "\n" << _pass << "\n";
       
    }
};

class Message {
public:
    std::string _text;
    std::string _sender;
    std::string _receiver;

    void loadFromFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cerr << "Couldn't open the file for reading: " << filename << std::endl;
            return;
        }
        std::string line;

        while (std::getline(infile, line)) {
            std::cout << line << " ";
        }
        std::cout << "\n";

    }

    void saveToFile(const std::string& filename) {
        std::ofstream outfile(filename);
        if (!outfile) {
            std::cerr << "Couldn't open the file for writing: " << filename << std::endl;
            return;
        }
        outfile << _text << "\n" << _sender << "\n" << _receiver << "\n";
    
    }
};

int main() {
   
    User user;
    Message message;
    
    const std::string userFile = "user_data.txt";

    fs::path file_path = "user_data.txt";
    fs::permissions(file_path, fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::replace);

    user._name = "Alex";
    user._login = "Al234";
    user._pass = "qwerty";
    user.saveToFile(userFile);
    user.loadFromFile(userFile);
 
    const std::string msgFile = "message_data.txt";

    fs::path file = "message_data.txt";
    fs::permissions(file, fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::replace);

    message._sender = user._name;
    message._receiver = user._name;
    message._text = "A message to yourself)";
    message.saveToFile(msgFile);
    message.loadFromFile(msgFile);

    return 0;
}