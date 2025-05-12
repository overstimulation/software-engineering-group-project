# Logowanie - overstimulation

| **Przypadek użycia**              | Logowanie                                                                                                                                                                                                                                                                                                   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Użytkownik pomyślnie loguje się do systemu.                                                                                                                                                                                                                                                                 |
| **Warunki wstępne**               | Użytkownik ma dostęp do interfejsu logowania systemu.                                                                                                                                                                                                                                                       |
| **Niezmienniki**                  | Proces logowania użytkownika jest w toku.                                                                                                                                                                                                                                                                   |
| **Opis**                          | - System wyświetla panel logowania.<br>- Użytkownik wprowadza poprawne dane logowania.<br>- System sprawdza, czy podane dane odpowiadają istniejącemu użytkownikowi i weryfikuje poprawność hasła.<br>- System loguje użytkownika.<br>- System wyświetla główny panel systemu dla zalogowanego użytkownika. |
| **Warunki końcowe**               | Logowanie użytkownika do systemu zostało przeprowadzone pomyślnie, a użytkownik ma dostęp do funkcji dostępnych po zalogowaniu.                                                                                                                                                                             |
| **Źródło ewentualnych problemów** | - Konto, do którego próbuje zalogować się użytkownik, nie istnieje, co skutkuje propozycją rejestracji.<br>- Dane wprowadzone przez użytkownika są niepoprawne (np. błędne hasło), co skutkuje wyświetleniem komunikatu o błędzie i prośbą o ponowne wprowadzenie danych.                                   |

# Rejestracja - overstimulation

| **Przypadek użycia**              | Rejestracja                                                                                                                                                                                                                                                                                    |
| --------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Użytkownik pomyślnie rejestruje się w systemie.                                                                                                                                                                                                                                                |
| **Warunki wstępne**               | Użytkownik ma dostęp do interfejsu rejestracji systemu.                                                                                                                                                                                                                                        |
| **Niezmienniki**                  | Proces rejestracji użytkownika jest w toku.                                                                                                                                                                                                                                                    |
| **Opis**                          | - System wyświetla panel rejestracji.<br>- Użytkownik wprowadza wymagane dane do rejestracji.<br>- System sprawdza poprawność wprowadzonych danych.<br>- Ponieważ dane są poprawne, System tworzy nowe konto użytkownika.<br>- System wyświetla komunikat informujący o pomyślnej rejestracji. |
| **Warunki końcowe**               | Nowe konto użytkownika zostało pomyślnie utworzone w systemie i jest gotowe do użycia (np. do zalogowania).                                                                                                                                                                                    |
| **Źródło ewentualnych problemów** | Dane wprowadzone przez użytkownika są niepoprawne (np. brak wymaganych pól, login już zajęty), co skutkuje wyświetleniem komunikatu o błędzie i prośbą o ponowne wprowadzenie danych.                                                                                                          |

# Weryfikacja - overstimulation

| **Przypadek użycia**              | Weryfikacja                                                                                                                                                                                                                                                            |
| --------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Pozytywna weryfikacja danych logowania.                                                                                                                                                                                                                                |
| **Warunki wstępne**               | Dane użytkownika wymagające weryfikacji są dostępne w systemie (zostały przekazane z przypadku użycia Logowanie).                                                                                                                                                      |
| **Niezmienniki**                  | Proces weryfikacji danych jest w toku.                                                                                                                                                                                                                                 |
| **Opis**                          | - System pobiera dane użytkownika przeznaczone do weryfikacji.<br>- System sprawdza poprawność i zgodność tych danych z danymi przechowywanymi w systemie.<br>- Ponieważ dane są poprawne, System potwierdza, że weryfikacja danych logowania zakończyła się sukcesem. |
| **Warunki końcowe**               | Weryfikacja danych logowania została przeprowadzona pomyślnie.                                                                                                                                                                                                         |
| **Źródło ewentualnych problemów** | Dane przekazane do systemu do weryfikacji są niepoprawne, co skutkuje nieudaną weryfikacją.                                                                                                                                                                            |

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

# Zarzadzanie uczestnikami - Emzeey

| **Przypadek użycia** |  Zarzadzanie uczestnikami   |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca chce dodać użytkownika do kursu.   |
| **Warunki wstępne**  |  Wykładowca przeszedł do menu zarządzania uczestnikami.   |
| **Niezmienniki**     |  Wykładowca wybiera dodanie użytkownika do kursu.   |
| **Opis**             |  System wyświetla menu wyboru opcji. Wykładowca wybiera opcję "Dodaj uzytkownika". Użytkownik zostaje pomyślnie dodany.   |
| **Warunki końcowe**  |  Użytkownik został dodany.    |

| **Przypadek użycia** |  Zarzadzanie uczestnikami   |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca chce usunąć użytkownika z kursu.   |
| **Warunki wstępne**  |  Wykładowca przeszedł do menu zarządzania uczestnikami i istnieje użytkownik możliwy do usunięcia.   |
| **Niezmienniki**     |  Wykładowca wybiera opcję usunięcia użytkownika z kursu.   |
| **Opis**             |  System wyświetla menu wyboru opcji. Wykładowca wybiera opcję "Usun uzytkownika". Użytkownik zostaje pomyślnie usunięty z kursu.   |
| **Warunki końcowe**  |  Użytkownik został usunięty.   |
| **Źródło ewentualnych problemów**  |  Brak użytkownika - wyświetlenie komunikatu o błędzie.   |

| **Przypadek użycia** |  Zarzadzanie uczestnikami   |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca chce przejść do menu zarządzania ocenami.   |
| **Warunki wstępne**  |  Wykładowca przeszedł do menu zarządzania uczestnikami i istnieje jakiś użytkownik.   |
| **Niezmienniki**     |  Wykładowca wybiera opcję zarządzania ocenami użytkownika.   |
| **Opis**             |  System wyświetla menu wyobru opcji. Wykładowca wybiera opcję "Zarzadzaj ocenami". System wyświetla menu zarządzania ocenami.   |
| **Warunki końcowe**  |  Wykładowca przeszedł do menu zarządzania ocenami.   |

# Zarządzanie ocenami - Emzeey

| **Przypadek użycia** |  Zarzadzanie ocenami   |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca dodaje ocenę użytkownikowi.   |
| **Warunki wstępne**  |  Wykładowca przeszedł do menu zarządzania ocenami.   |
| **Niezmienniki**     |  Wykładowca wybiera opcję dodania oceny.   |
| **Opis**             |  System wyświetla panel zarządzania ocenami. Wykładowca wybiera użytkownika. System sprawdza czy użytkownik istnieje. Jeżeli użytkownik istnieje, to wykładowca wybiera opcję dodania oceny, podaje przemiot i ocenę. System dodaje ocenę do ocen użytkownika.   |
| **Warunki końcowe**  |  Ocena została poprawnie dodana.   |
| **Źródło ewentualnych problemów**  |  Brak użytkownika - wyświetlenie komunikatu o błędzie.   |

| **Przypadek użycia** |  Zarzadzanie ocenami   |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca usuwa ocenę użytkownikowi.   |
| **Warunki wstępne**  |  Wykładowca przeszedł do menu zarządzania ocenami.   |
| **Niezmienniki**     |  Wykładowca wybiera opcję usunięcia oceny.   |
| **Opis**             |  System wyświetla panel zarządzania ocenami. Wykładowca wybiera użytkownika. System sprawdza czy użytkownik istnieje. Jeżeli użytkownik istnieje, to wykładowca wybiera opcję usunięcia oceny, podaje przemiot i ocenę. System usuwa ocenę z ocen użytkownika.   |
| **Warunki końcowe**  |  Ocena została poprawnie usunięta.   |
| **Źródło ewentualnych problemów**  |  Brak użytkownika - wyświetlenie komunikatu o błędzie.   |

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

# Stworz skrzynke - DeKa

| **Przypadek użycia**              |   Stwórz Skrzynkę  |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    |  Utworzenie nowej skrzynki   |
| **Warunki wstępne**               |  Wykładowca ma dostęp do funkcji tworzenia skrzynki   |
| **Niezmienniki**                  |  Wykładowca wysyła zapytanie o utworzenie skrzynki   |
| **Opis**                          |  Wykładowca wybiera opcję „Stwórz skrzynkę”. Wprowadza nazwę i opis skrzynki. System weryfikuje poprawność danych. Po pozytywnej weryfikacji skrzynka zostaje utworzona, a wykładowca otrzymuje komunikat o powodzeniu operacji.   |
| **Warunki końcowe**               |  Skrzynka zostaje utworzona   |
| **Źródło ewentualnych problemów** |  Błędne lub niepełne dane w formularzu – system wyświetla komunikat o błędzie i prosi o ponowne wprowadzenie danych |

# Sprawdz oceny - Emzeey

| **Przypadek użycia** |  Sprawdz oceny   |
| -------------------- | --- |
| **Scenariusz**       |  Otrzymanie spisu ocen.   |
| **Warunki wstępne**  |  Student jest zalogowany.   |
| **Niezmienniki**     |  Student wybiera spis ocen do pokazania. Student zamyka spis.   |
| **Opis**             |  System wyświetla stronę profilu stidenta. Student wybiera jaki spis ocen chce zobaczyć. System wyświetla oceny. Student zamyka spis ocen.   |
| **Warunki końcowe**  |  Student sprawdził oceny. Panel ocen zostaje zamknięty.   |

# Poczta - overstimulation

| **Przypadek użycia**              | Poczta                                                                                                                                                                                                                                    |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Dostęp do panelu poczty i wybór przeglądania wiadomości.                                                                                                                                                                                  |
| **Warunki wstępne**               | Użytkownik jest zalogowany do systemu i ma dostęp do funkcji Poczty.                                                                                                                                                                      |
| **Niezmienniki**                  | Użytkownik pozostaje uwierzytelniony, moduł poczty jest dostępny.                                                                                                                                                                         |
| **Opis**                          | - System wyświetla główny panel modułu poczty, prezentując dostępne opcje.<br>- Użytkownik wybiera opcję "Sprawdź wiadomości".<br>- System inicjuje proces przeglądania wiadomości (przechodzi do przypadku użycia "Sprawdź wiadomości"). |
| **Warunki końcowe**               | Użytkownik wszedł do modułu poczty, wybrał opcję "Sprawdź wiadomości", a system rozpoczął realizację tego podprocesu.                                                                                                                     |
| **Źródło ewentualnych problemów** | Użytkownik wybiera opcję "Wyślij wiadomość" (realizowany jest inny scenariusz pomyślny).                                                                                                                                                  |

| **Przypadek użycia** | Poczta                                                                                                                                                                                                                                         |
| -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**       | Dostęp do panelu poczty i wybór wysyłania wiadomości.                                                                                                                                                                                          |
| **Warunki wstępne**  | Użytkownik jest zalogowany do systemu i ma dostęp do funkcji Poczty.                                                                                                                                                                           |
| **Niezmienniki**     | Użytkownik pozostaje uwierzytelniony, moduł poczty jest dostępny.                                                                                                                                                                              |
| **Opis**             | - System wyświetla główny panel modułu poczty, prezentując dostępne opcje.<br>- Użytkownik wybiera opcję "Wyślij wiadomość".<br>- System inicjuje proces tworzenia i wysyłania wiadomości (przechodzi do przypadku użycia "Wyślij wiadomość"). |
| **Warunki końcowe**  | Użytkownik wybiera opcję "Sprawdź wiadomości" (realizowany jest inny scenariusz pomyślny).                                                                                                                                                     |

# Wyślij wiadomość - overstimulation

| **Przypadek użycia**              | Wyślij wiadomość                                                                                                                                                                                                                                                                                                                                                                            |
| --------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Pomyślne wysłanie wiadomości.                                                                                                                                                                                                                                                                                                                                                               |
| **Warunki wstępne**               | Użytkownik jest zalogowany do systemu i wybrał opcję wysłania wiadomości w module Poczty.                                                                                                                                                                                                                                                                                                   |
| **Niezmienniki**                  | Użytkownik pozostaje uwierzytelniony, funkcjonalność wysyłania wiadomości jest dostępna.                                                                                                                                                                                                                                                                                                    |
| **Opis**                          | - System wyświetla panel umożliwiający stworzenie i wysłanie nowej wiadomości.<br>- Użytkownik wprowadza adres odbiorcy wiadomości.<br>- Użytkownik wprowadza temat wiadomości.<br>- Użytkownik wprowadza treść wiadomości.<br>- System przetwarza wprowadzone dane i wysyła wiadomość do wskazanego odbiorcy.<br>- System wyświetla komunikat potwierdzający pomyślne wysłanie wiadomości. |
| **Warunki końcowe**               | Wiadomość została pomyślnie wysłana do wskazanego odbiorcy, a użytkownik otrzymał potwierdzenie operacji.                                                                                                                                                                                                                                                                                   |
| **Źródło ewentualnych problemów** | Użytkownik nie wprowadzi wszystkich wymaganych danych (np. odbiorcy, tematu, treści).                                                                                                                                                                                                                                                                                                       |

# Sprawdź wiadomości - overstimulation

| **Przypadek użycia**              | Sprawdź wiadomości                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| --------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scenariusz**                    | Pomyślne przeglądanie i odczytanie wiadomości.                                                                                                                                                                                                                                                                                                                                                                                                                               |
| **Warunki wstępne**               | Użytkownik jest zalogowany do systemu i wybrał opcję "Sprawdź wiadomości" w module Poczty.                                                                                                                                                                                                                                                                                                                                                                                   |
| **Niezmienniki**                  | Użytkownik pozostaje uwierzytelniony, moduł przeglądania wiadomości jest dostępny.                                                                                                                                                                                                                                                                                                                                                                                           |
| **Opis**                          | - System pobiera wiadomości przypisane do użytkownika.<br>- System wyświetla listę wiadomości użytkownika.<br>- Użytkownik przegląda listę wiadomości i wybiera opcję "wybierz wiadomość".<br>- Użytkownik wskazuje, którą wiadomość chce odczytać.<br>- System wyświetla pełną treść wybranej wiadomości.<br>- Użytkownik zapoznaje się z treścią wiadomości.<br>- Użytkownik wybiera opcję "wyjdź" z widoku wiadomości.<br>- System kończy proces przeglądania wiadomości. |
| **Warunki końcowe**               | Użytkownik pomyślnie odczytał wiadomość i zakończył sesję przeglądania wiadomości.                                                                                                                                                                                                                                                                                                                                                                                           |
| **Źródło ewentualnych problemów** | - Użytkownik wybiera opcję "wyjdź" bezpośrednio z listy wiadomości (realizowany jest inny, krótszy scenariusz pomyślny).<br>- Użytkownik wybiera opcję "wróć do listy wiadomości" z widoku wiadomości (następuje powrót do kroku 2/3, a nie zakończenie scenariusza w tym miejscu).                                                                                                                                                                                          |

# Wyloguj - Emzeey

| **Przypadek użycia** |  Wyloguj   |
| -------------------- | --- |
| **Scenariusz**       |  Pomyślne wylogowanie z systemu.   |
| **Warunki wstępne**  |  Użytkownik jest zalogowany.   |
| **Niezmienniki**     |  Użytkownik wybiera opcję wylogowania.   |
| **Opis**             |  Użytkownik wybiera opcję wylogowania. System zmienia status użytkownika na wylogowany i wyświetla powiadoemienie o wylogowaniu.   |
| **Warunki końcowe**  |  Użytkownik jest wylogowany.   |
