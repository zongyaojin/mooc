#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const { return name; }
    std::string get_artist() const { return artist; }
    int get_rating() const { return rating; }
    bool operator<(const Song &rhs) const { return this->name < rhs.name; }
    bool operator==(const Song &rhs) const { return this->name == rhs.name; }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu();
void display_ruler();
void play_current_song(const std::list<Song>::const_iterator &current_song);
void display_playlist(const std::list<Song> &playlist);
void play_first_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song);
void play_next_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song);
void play_last_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song);
void play_previous_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song);
void add_and_play_new_song(std::list<Song> &playlist, std::list<Song>::const_iterator &current_song);

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::const_iterator current_song = playlist.begin();
    display_playlist(playlist);
    std::cout << "Playing: " << *current_song << std::endl;
    
    char input {'d'};
    while (input != 'q') {
        display_menu();
        std::cin >> input;
        input = std::tolower(input);
        switch (input) {
            case 'f':
                play_first_song(playlist, current_song);
                break;
            case 'l':
                play_last_song(playlist, current_song);
                break;
            case 'n':
                play_next_song(playlist, current_song);
                break;
            case 'p':
                play_previous_song(playlist, current_song);
                break;
            case 'a':
                add_and_play_new_song(playlist, current_song);
                break;
            case 'd':
                display_playlist(playlist);
                std::cout << "Playing: " << *current_song << std::endl;
                break;
            case 'q':
                break;
            default:
                std::cout << "Invalid selection." << std::endl;
        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}

void display_menu() {
    std::cout << "\n\033[1;32mF - Play First Song" << std::endl;
    std::cout << "L - Play Last Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "D - Display the current playlist \033[0m" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit):";
}

void display_ruler() {
    std::cout << std::setw(60) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void play_current_song(const std::list<Song>::const_iterator &current_song) {
    std::cout << "Playing: " << *current_song << std::endl;
}


void display_playlist(const std::list<Song> &playlist) {
    std::cout << std::endl << std::endl << std::endl;
    for (const auto &song:playlist)
        std::cout << song << std::endl;
    display_ruler();
}

void play_first_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song) {
    display_playlist(playlist);
    current_song = playlist.begin();
    play_current_song(current_song);
}

void play_last_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song) {
    display_playlist(playlist);
    current_song = --playlist.end();
    play_current_song(current_song);
}

void play_next_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song) {
    if (current_song != --playlist.end()) {
        display_playlist(playlist);
        ++current_song;
        play_current_song(current_song);
    } else {
        play_first_song(playlist, current_song);
    }
}

void play_previous_song(const std::list<Song> &playlist, std::list<Song>::const_iterator &current_song) {
    if (current_song != playlist.begin()) {
        display_playlist(playlist);
        --current_song;
        play_current_song(current_song);
    } else {
        play_last_song(playlist, current_song);
    }
}

void add_and_play_new_song(std::list<Song> &playlist, std::list<Song>::const_iterator &current_song) {
    std::string name, artist;
    int rating{0};
    std::cout << "Enter song name, artist, rating (1-5): ";
    std::cin >> name >> artist >> rating;
    current_song = playlist.emplace(current_song, name, artist, rating);
    display_playlist(playlist);
    play_current_song(current_song);
}
