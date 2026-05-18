#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct Song {
    std::wstring artist;
    std::wstring title;

    Song(const std::wstring& a, const std::wstring& t) : artist(a), title(t) {
        std::wcout << L"[konstruktor] " << artist << L" - " << title << "\n";
    }

    ~Song() {
        std::wcout << L"[destruktor]  " << artist << L" - " << title << "\n";
    }
};

template <typename... Args>
std::unique_ptr<Song> SongFactory(Args&&... args) {
    return std::make_unique<Song>(std::forward<Args>(args)...);
}

int main() {
    auto song = SongFactory(L"Michael Jackson", L"Beat It");
    std::wcout << L"Uzywam: " << song->title << L"\n";

    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(std::make_unique<Song>(L"B'z", L"Juice"));
    songs.push_back(std::make_unique<Song>(L"Namie Amuro", L"Funky Town"));
    songs.push_back(std::make_unique<Song>(L"Ayumi", L"Poker Face"));

    std::wcout << L"\n lista piosenek \n";

    for (const auto& s : songs) {
        std::wcout << s->artist << L" - " << s->title << L"\n";
    }

    // for (auto s : songs) {...} to błąd kompilacji, poniewaz próbujemy kopiowac unique_ptr

    std::wcout << L"\n koniec main - destruktory\n";
    return 0;
}