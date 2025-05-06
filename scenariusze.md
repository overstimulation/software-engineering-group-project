#Sprawdz oceny - DeKa
| **Przypadek użycia** | Stwórz Kurs    |
| -------------------- | --- |
| **Scenariusz**       |  Utworzenie Kursu   |
| **Warunki wstępne**  |  Wykladowca ma dostep do tworzenia kursu   |
| **Niezmienniki**     |  Wykladowca wysyla zapytanie do serwera o utworzenie Kursu   |
| **Opis**             |  Wykładowca loguje się do systemu. Następnie przechodzi do panelu zarządzania kursami. Wybiera opcję „Utwórz nowy kurs”. Wprowadza wymagane dane kursu, takie jak nazwa, opis. Klikając przycisk „Zatwierdź”, wykładowca wysyła zapytanie do serwera o utworzenie kursu. System weryfikuje poprawność danych i uprawnienia wykładowcy. Jeśli dane są poprawne, system tworzy kurs i wyświetla komunikat o pomyślnym utworzeniu kursu.|
| **Warunki końcowe**  | 	Kurs zostaje utworzony,wykladowca otrzymuje komunikat o pomyslnym utworzeniu Kursu    |




| **Przypadek użycia** |   Stwórz Skrzynkę  |
| -------------------- | --- |
| **Scenariusz**       |  Utworzenie skrzynki   |
| **Warunki wstępne**  |  Użytkownik ma dostęp do funkcji tworzenia skrzynki   |
| **Niezmienniki**     |  Użytkownik inicjuje proces tworzenia skrzynki   |
| **Opis**             |  Użytkownik loguje się do systemu i przechodzi do sekcji zarządzania skrzynkami. Wybiera opcję „Stwórz nową skrzynkę”. Wprowadza wymagane dane, takie jak nazwa i opis skrzynki. Klikając „Zatwierdź”, wysyła żądanie do serwera. System weryfikuje poprawność danych oraz uprawnienia użytkownika. Po pozytywnej weryfikacji skrzynka zostaje utworzona, a użytkownik otrzymuje komunikat o powodzeniu operacji.   |
| **Warunki końcowe**  |  Skrzynka zostaje utworzona, Wykladowca otrzymuje potwierdzenie   |





| **Przypadek użycia** |   Zarzadzanie plikami kursu  |
| -------------------- | --- |
| **Scenariusz**       |   Dodanie pliku   |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operację dodania pliku   |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i wybiera zakładkę „Pliki”. Następnie klika przycisk „Dodaj plik”, wybiera plik z lokalnego dysku i zatwierdza. System sprawdza format, rozmiar i uprawnienia. Po pomyślnej weryfikacji plik zostaje zapisany i powiązany z kursem.  |
| **Warunki końcowe**  |   Plik zostaje dodany do kursu, a wykładowca otrzymuje potwierdzenie operacji   |

| **Przypadek użycia** |   Zarzadzanie plikami kursu  |
| -------------------- | --- |
| **Scenariusz**       |   Usuniecie pliku   |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operację usunięcia pliku  |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i wybiera zakładkę „Pliki”. Na liście plików znajduje żądany plik i wybiera opcję „Usuń”. System prosi o potwierdzenie operacji, a po jego udzieleniu usuwa plik z bazy danych i serwera.  |
| **Warunki końcowe**  |  Plik zostaje trwale usunięty z kursu, a wykładowca otrzymuje komunikat o prawidlowym usunięcia   |

| **Przypadek użycia** |  Zarzadzanie plikami kursu    |
| -------------------- | --- |
| **Scenariusz**       |   Edycja pliku  |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operacje edycji pliku  |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i otwiera zakładkę „Pliki”. Wybiera plik, który chce edytować, i przechodzi do formularza edycji. Wprowadza zmiany, np. nową nazwę lub opis pliku, a następnie zapisuje zmiany. System weryfikuje dane i aktualizuje informacje o pliku.  |
| **Warunki końcowe**  |   Informacje o pliku zostają zaktualizowane, a wykładowca otrzymuje komunikat potwierdzający edycję |

| **Przypadek użycia** |  Zarzadzanie Kursami   |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcje zarzadzania skrzynką plików  |
| **Warunki wstępne**  |   Wykładwoca jest zalogowany oraz posiada podstęp do zarządzania kursem  |
| **Niezmienniki**     |   Wykładowca wybiera opcje zarządzania skrzynką plików  |
| **Opis**             |   Wykładowca wchodzi do menu zarzadzania kursami. W panelu kursu wybiera opcję „Skrzynki plików”. System weryfikuje uprawnienia użytkownika i ładuje interfejs zarządzania skrzynkami. Wykładowca uzyskuje dostęp do listy istniejących skrzynek oraz opcji tworzenia nowych, edycji i usuwania.  |
| **Warunki końcowe**  |   Wykławdowca przechodzi do menu zarządzania skrzynką plików  |

| **Przypadek użycia** |   Zarzadzanie Kursem   |
| -------------------- | --- |
| **Scenariusz**       |    Wykładowca wybiera opcje do utworzenia nowego kursu |
| **Warunki wstępne**  |    Wykładwoca jest zalogowany oraz posiada podstęp do tworzenia kursu |
| **Niezmienniki**     |    Wykładowca wybiera opcje  tworzenia kursu |
| **Opis**             |    	Wykładowca wchodzi do menu zarządzania kursami. Wybiera opcję „Stwórz kurs”. System prezentuje formularz tworzenia kursu. Wykładowca wprowadza wymagane dane: nazwę kursu, opis. Po zatwierdzeniu formularza system weryfikuje poprawność danych i tworzy nowy kurs w bazie. |
| **Warunki końcowe**  |  Nowy kurs zostaje dodany do listy kursów i jest widoczny dla wykładowcy   |

| **Przypadek użycia** |   Zarzadzanie Kursem  |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca wybiera opcje do zarzadzania plikami kursu  |
| **Warunki wstępne**  |   Wykładowca jest zalogowany oraz posiada dostep do zarzadzania plikami kursu  |
| **Niezmienniki**     |   Wykładowca wybiera opcje zarzadznia plikami kursu  |
| **Opis**             |   Wykładowca loguje się do systemu i przechodzi do wybranego kursu. Następnie wybiera z menu kursu opcję „Zarzadzanie pliki kursu”. System sprawdza uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania plikami, w którym dostępne są opcje dodawania, edycji oraz usuwania plików związanych z kursem.  |
| **Warunki końcowe**  |  Wykładwoca przechodzi do menu zarządzania plikami kursu   |

| **Przypadek użycia** |  Zarzadzanie Kursem    |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcję do zarządzania uczestnikami kursu  |
| **Warunki wstępne**  |  Wykładowca jest zalogowany oraz posiada dostęp do zarządzania uczestnikami kursu   |
| **Niezmienniki**     |   Wykładowca wybiera opcję zarządzania uczestnikami kursu  |
| **Opis**             |   	Wykładowca loguje się do systemu i przechodzi do wybranego kursu. W menu kursu wybiera opcję „Zarządzanie uczestnikami”. System weryfikuje uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania uczestnikami kursu, umożliwiając dodawanie, usuwanie lub edytowanie listy uczestników.  |
| **Warunki końcowe**  |  Wykładowca przechodzi do menu zarządzania uczestnikami kursu   |

| **Przypadek użycia** |     |
| -------------------- | --- |
| **Scenariusz**       |     |
| **Warunki wstępne**  |     |
| **Niezmienniki**     |     |
| **Opis**             |     |
| **Warunki końcowe**  |     |




