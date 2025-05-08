# Zarządzanie kursem - DeKa

| **Przypadek użycia**              |  Zarządzanie Kursem   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |   Wykładowca wybiera opcję zarządzania skrzynką plików  |
| **Warunki wstępne**               |   Wykładowca jest zalogowany oraz posiada dostęp do zarządzania kursem  |
| **Niezmienniki**                  |   Wykładowca wybiera opcję zarządzania skrzynką plików  |
| **Opis**                          |   Wykładowca wchodzi do menu zarządzania kursami. W panelu kursu wybiera opcję „Skrzynki plików”. System weryfikuje uprawnienia użytkownika i ładuje interfejs zarządzania skrzynkami. Wykładowca uzyskuje dostęp do listy istniejących skrzynek. |
| **Warunki końcowe**               |   Wykładowca przechodzi do menu zarządzania skrzynką plików  |
| **Źródło ewentualnych problemów** |   Brak wybranej skrzynki - Wykładowca otrzymuje komunikat, że podana skrzynka nie istnieje |

| **Przypadek użycia**              |   Zarządzanie Kursem  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Wykładowca wybiera opcję zarządzania plikami kursu  |
| **Warunki wstępne**               |  Wykładowca jest zalogowany  |
| **Niezmienniki**                  |  Wykładowca wybiera opcję zarządzania plikami kursu  |
| **Opis**                          |  Wykładowca wybiera z menu kursu opcję „Zarządzanie plikami kursu”. System sprawdza uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania plikami, w którym dostępne są opcje dodawania, edycji oraz usuwania plików związanych z kursem.  |
| **Warunki końcowe**               |  Wykładowca przechodzi do menu zarządzania plikami kursu   |
| **Źródło ewentualnych problemów** |  Brak wybranego kursu – wykładowca otrzymuje komunikat, że podany kurs nie istnieje |

| **Przypadek użycia**              |  Zarządzanie Kursem    |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Wykładowca wybiera opcję zarządzania uczestnikami kursu  |
| **Warunki wstępne**               |  Wykładowca jest zalogowany oraz posiada dostęp do zarządzania uczestnikami kursu   |
| **Niezmienniki**                  |  Wykładowca wybiera opcję zarządzania uczestnikami kursu  |
| **Opis**                          |  Wykładowca wybiera opcję „Zarządzanie uczestnikami”. System weryfikuje dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania uczestnikami kursu.  |
| **Warunki końcowe**               |  Wykładowca przechodzi do menu zarządzania uczestnikami kursu   |
| **Źródło ewentualnych problemów** |  Brak wybranego kursu - wykładowca otrzymuje komunikat, że podany kurs nie istnieje |


# Stworz kurs - DeKa


| **Przypadek użycia**              | Stwórz Kurs    |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Utworzenie nowego kursu   |
| **Warunki wstępne**               |  Wykładowca jest zalogowany   |
| **Niezmienniki**                  |  Wykładowca wysyła zapytanie o utworzenie kursu   |
| **Opis**                          |   Wykładowca wybiera opcję „Utwórz nowy kurs”. System wyświetla panel tworzenia nowego kursu. Wykładowca wprowadza nazwę i opis. Klikając przycisk „Zatwierdź”, wykładowca wysyła zapytanie o utworzenie kursu. System weryfikuje poprawność danych. Jeśli dane są poprawne, system tworzy kurs i wyświetla komunikat o pomyślnym utworzeniu kursu.|
| **Warunki końcowe**               | 	Kurs zostaje utworzony, wykładowca otrzymuje komunikat o pomyślnym utworzeniu kursu    |
| **Źródło ewentualnych problemów** | Błędne lub niepełne dane w formularzu – system wyświetla komunikat o błędzie i prosi o ponowne wprowadzenie danych |


# Stworz skrzynke - DeKa

| **Przypadek użycia**              |   Stwórz Skrzynkę  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Utworzenie nowej skrzynki   |
| **Warunki wstępne**               |  Wykładowca ma dostęp do funkcji tworzenia skrzynki   |
| **Niezmienniki**                  |  Wykładowca wysyła zapytanie o utworzenie skrzynki   |
| **Opis**                          |  Wykładowca wybiera opcję „Stwórz skrzynkę”. Wprowadza nazwę i opis skrzynki. System weryfikuje poprawność danych. Po pozytywnej weryfikacji skrzynka zostaje utworzona, a wykładowca otrzymuje komunikat o powodzeniu operacji.   |
| **Warunki końcowe**               |  Skrzynka zostaje utworzona   |
| **Źródło ewentualnych problemów** |  Błędne lub niepełne dane w formularzu – system wyświetla komunikat o błędzie i prosi o ponowne wprowadzenie danych |


# Zarządzanie plikami kursu - DeKa


| **Przypadek użycia**              |   Zarządzanie plikami kursu  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |   Dodanie pliku   |
| **Warunki wstępne**               |   Wykładowca ma uprawnienia do zarządzania plikami  |
| **Niezmienniki**                  |   Wykładowca wykonuje operację dodania pliku   |
| **Opis**                          |   Wykładowca wybiera „Dodaj plik”, wybiera plik z lokalnego dysku i zatwierdza. System sprawdza format, rozmiar i uprawnienia. Po pomyślnej weryfikacji plik zostaje zapisany i dodany do kursu. Wykładowca otrzymuje komunikat o powodzeniu operacji  |
| **Warunki końcowe**               |   Plik zostaje dodany do kursu   |
| **Źródło ewentualnych problemów** |   Nieobsługiwany format pliku – system odrzuca plik i wyświetla komunikat o dozwolonych typach.<br> Przekroczony maksymalny rozmiar pliku – system informuje o limicie i prosi o zmniejszenie rozmiaru.<br>Brak odpowiednich uprawnień – system uniemożliwia dodanie pliku i wyświetla komunikat o braku dostępu.|

| **Przypadek użycia**              |   Zarządzanie plikami kursu  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |   Usunięcie pliku   |
| **Warunki wstępne**               |   Wykładowca ma uprawnienia do zarządzania plikami  |
| **Niezmienniki**                  |   Wykładowca wykonuje operację usunięcia pliku  |
| **Opis**                          |   Wykładowca znajduje na liście plików żądany plik i wybiera opcję „Usuń plik”. System prosi o potwierdzenie operacji, a po potwierdzeniu usuwa plik z bazy danych i serwera. Wykładowca otrzymuje komunikat o powodzeniu operacji  |
| **Warunki końcowe**               |   Plik zostaje trwale usunięty z kursu.  |
| **Źródło ewentualnych problemów** |   Brak potwierdzenia usunięcia – system anuluje operację i nie usuwa pliku. |

| **Przypadek użycia**              |  Zarządzanie plikami kursu    |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |   Edycja pliku  |
| **Warunki wstępne**               |   Wykładowca ma uprawnienia do zarządzania plikami  |
| **Niezmienniki**                  |   Wykładowca wykonuje operacje edycji pliku  |
| **Opis**                          |   Wykładowca wybiera plik, który chce edytować, i przechodzi do formularza edycji. Wprowadza zmiany, np. nową nazwę lub opis pliku, a następnie zapisuje zmiany. System weryfikuje dane i aktualizuje informacje o pliku. System wyświetlna komunikat o prawidlowej edycji pliku. |
| **Warunki końcowe**               |   Informacje o pliku zostają zaktualizowane, a wykładowca otrzymuje komunikat potwierdzający edycję |
| **Źródło ewentualnych problemów** |   Podana nazwa istnieje - Wykładowca proszony jest o podanie innej nazwy |

# Zarządzanie plikami(na skrzynce) - DeKa


| **Przypadek użycia**              |   Zarządzanie plikami   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Sprawdzenie pliku przez Wykladowce   |
| **Warunki wstępne**               |  Użytkownik zalogowany jako wykładowca, posiada dostęp do kursu i odpowiednich plików     |
| **Niezmienniki**                  |  Wykładowca wybiera opcję do przegladania plikow na skrzynce  |
| **Opis**                          |  Wykładowca przechodzi do skrzynki z plikami, w której chce sprawdzić plik. System weryfikuje dostęp wykładowcy do pliku. Po pozytywnej weryfikacji system wyświetla zawartość pliku, lub umożliwia jego pobranie.   |
| **Warunki końcowe**               |  Wykładowca dostaje dostęp do zawartości pliku lub do pobrania go  |
| **Źródło ewentualnych problemów** |  Brak odpowiednich uprawnień – system odmawia dostępu do pliku i informuje o braku autoryzacji.<br>Uszkodzony plik – system wyświetla komunikat o uszkodzeniu pliku, uniemożliwiając jego otwarcie. |


| **Przypadek użycia**              |   Zarządzanie plikami   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |   Dodanie pliku przez studenta do skrzynki  |
| **Warunki wstępne**               |   Użytkownik zalogowany jako Student, posiada dostęp do kursu i dodawania plikow do skrzynki   |
| **Niezmienniki**                  |   Student wybiera opcję dodania pliku do skrzynki |
| **Opis**                          |   Student wybiera opcję „Dodaj plik do skrzynki”. System weryfikuje, czy student ma odpowiednie uprawnienia do dodawania plików do skrzynki. Po pozytywnej weryfikacji, student wybiera plik z urządzenia, który chce dodać do skrzynki. System sprawdza, czy plik spełnia wymagania (np. rozmiar, format). Po zatwierdzeniu pliku, system dodaje go do odpowiedniej skrzynki.  |
| **Warunki końcowe**               |   Plik pomyślnie dodany do skrzynki plików w kursie |
| **Źródło ewentualnych problemów** |   Brak odpowiednich uprawnień – system odmawia dostępu do funkcji dodawania pliku i informuje studenta o braku autoryzacji.<br>Niekompatybilny format pliku – system informuje studenta, jeśli plik ma nieobsługiwany format i prosi o wybór odpowiedniego pliku.<br>Zbyt duży plik – system zgłasza błąd, jeśli plik przekracza dozwolony rozmiar i prosi o wybór mniejszego pliku.<br>Brak przestrzeni w skrzynce – jeśli skrzynka plików jest pełna, system informuje o braku miejsca na dodanie nowego pliku. |


# Zarządzanie skrzynka plikow - DeKa

| **Przypadek użycia**              |   Zarządzanie skrzynka plikow   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Wykładowca wybiera opcję do tworzenia skrzynki  |
| **Warunki wstępne**               |  Wykładowca posiada dostęp do tworzenia nowej skrzynki    |
| **Niezmienniki**                  |  Wykładowca wybiera opcję do tworzenia skrzynki   |
| **Opis**                          |  Wykładowca przechodzi do kursu, w którym chce utworzyć nową skrzynkę plików. W menu kursu wybiera opcję „Stwórz skrzynkę”. System weryfikuje uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje formularz tworzenia nowej skrzynki.  |
| **Warunki końcowe**               |  Wykładowca przechodzi do menu tworzenia nowej skrzynki   |
| **Źródło ewentualnych problemów** |  Brak odpowiednich uprawnień – system odmawia dostępu do tworzenia skrzynki i informuje wykładowcę o braku autoryzacji.<br>Błąd w dostępności kursu – system informuje, że kurs, w którym wykładowca chce utworzyć skrzynkę, nie jest dostępny. |


| **Przypadek użycia**              |   Zarządzanie skrzynka plikow   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Wykładowca wybiera opcję do zarządzania plikami w skrzynce  |
| **Warunki wstępne**               |  Wykładowca prawidłowo przeszedł do menu zarządzania skrzynka plikow    |
| **Niezmienniki**                  |  Wykładowca wybiera opcję do zarządzania plikami w skrzynce   |
| **Opis**                          |  Wykładowca przechodzi do wybranego kursu, który zawiera skrzynkę plików. W menu kursu wybiera opcję „Zarządzanie plikami”. System weryfikuje uprawnienia wykładowcy oraz dostępność skrzynki. Po pozytywnej weryfikacji, system ładuje interfejs zarządzania plikami.  |
| **Warunki końcowe**               |  Wykładowca przechodzi do menu zarządzania plikami na skrzynce   |
| **Źródło ewentualnych problemów** |  Brak odpowiednich uprawnień – system odmawia edycji pliku i informuje o braku dostępu.|







