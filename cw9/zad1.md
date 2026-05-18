Inteligentny wskaźnik to obiekt opakowujący surowy wskaźnik, który automatycznie wywołuje delete w swoim destruktorze, nie musimy pamiętać o zwalnianiu pamięci, dzieje się to samo gdy wskaźnik wychodzi poza zasięg.

unique_ptr ma dokładnie jednego właściciela — nie można go kopiować, tylko przenosić przez std::move. Jest tak samo szybki i mały jak surowy wskaźnik. To domyślny wybór.

shared_ptr pozwala wielu wskaźnikom wskazywać na ten sam obiekt. Trzyma licznik referencji i obiekt jest usuwany dopiero gdy ostatni shared_ptr wychodzi z zasięgu. Przez ten licznik jest nieco większy i wolniejszy niż unique_ptr. Używamy go tylko gdy faktycznie potrzebujemy współdzielonej własności.
