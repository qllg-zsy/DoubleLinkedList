#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#include "DoubleLinkedList.hpp"

struct ScoreEntry {
    int score;
    std::string username;
};

std::ostream& operator<<(std::ostream& os, const ScoreEntry& entry) {
    os << "Score: " << entry.score << ", Username: " << entry.username << std::endl;;
    return os;
}


int main() {
    std::ifstream file("Scores.txt");
    if (!file) {
        std::cout << "cannot open file" << std::endl;
    }

    std::vector<ScoreEntry> scoredata;
    int score;
    std::string username;

    doubleLinkedListNode<ScoreEntry> node;
    doubleLinkedList<ScoreEntry> list;
    while (file >> score >> username) {
        ScoreEntry entry;
        entry.score = score;
        entry.username = username;
        list.insertNodeBytail(entry);
    }

    list.printLinkedList();

    return 0;
}

