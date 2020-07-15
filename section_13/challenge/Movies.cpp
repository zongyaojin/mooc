#include <iostream>
#include "Movies.h"

Movies::Movies() {}

Movies::~Movies() {}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (auto m:movies) {
        if (m.get_name() == name)
            return false;
    }
    movies.emplace_back(name, rating, watched);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto &m:movies) {
        if (m.get_name() == name) {
            m.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.size() == 0) {
        std::cout << "Sorry, no movies to display.\n" << std::endl;
        return;
    }
    std::cout << "\n====================" << std::endl;
    for (auto m:movies)
        m.display();
    std::cout << "====================\n" << std::endl;
}