Zaimplementowałem `SongFactory` jako szablon, który przekazuje parametry wprost do konstruktora i zwraca wskaźnik wyłączny `std::unique_ptr<Song>`.

Do struktury `Song` dodałem wypisywanie do konsoli. Dzięki temu podczas wywoływania kodu widać, że w momencie utworzenia wskaźnika wywołuje się konstruktor obiektu, a gdy wektor lub zmienna wychodzi z zasięgu na końcu programu, automatycznie wywoływany jest destruktor. Nie muszę sam używać słowa kluczowego `delete` po to by zwolnić pamięć.

Wypełniłem tablicę `std::vector<std::unique_ptr<Song>> songs` tworząc obiekty przy użyciu `std::make_unique`. Chcąc wypisać te piosenki zakresową pętlą "for" musiałem skorzystać z referencji (`const auto& s : songs`). Inteligentny wskaźnik typu `unique_ptr` można jedynie przenieść, a jego konstruktor kopiujący został celowo usunięty. Próba wykonania tradycyjnej pętli iterującej po wartości (`auto s : songs`) próbuje wykonać niedozwoloną kopię i kończy się błędem kompilacji.
