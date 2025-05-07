# Zarzadzanie kursem - DeKa

| **Przypadek użycia** |  Zarzadzanie Kursem   |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcje zarzadzania skrzynką plików  |
| **Warunki wstępne**  |   Wykładwoca jest zalogowany oraz posiada podstęp do zarządzania kursem  |
| **Niezmienniki**     |   Wykładowca wybiera opcje zarządzania skrzynką plików  |
| **Opis**             |   Wykładowca wchodzi do menu zarzadzania kursami. W panelu kursu wybiera opcję „Skrzynki plików”. System weryfikuje uprawnienia użytkownika i ładuje interfejs zarządzania skrzynkami. Wykładowca uzyskuje dostęp do listy istniejących skrzynek. |
| **Warunki końcowe**  |   Wykławdowca przechodzi do menu zarządzania skrzynką plików  |
| **Źródło ewentualnych problemów** | Brak wybranej skrzynki-Wykładwoca otrzymuje komunikat, że podana skrzynka nie istnieje |

| **Przypadek użycia** |   Zarzadzanie Kursem   |
| -------------------- | --- |
| **Scenariusz**       |    Wykładowca wybiera opcje do utworzenia nowego kursu |
| **Warunki wstępne**  |    Wykładwoca jest zalogowany oraz posiada podstęp do tworzenia kursu |
| **Niezmienniki**     |    Wykładowca wybiera opcje  tworzenia kursu |
| **Opis**             |    	Wykładowca wchodzi do menu zarządzania kursami. Wybiera opcję „Stwórz kurs”. System prezentuje formularz tworzenia kursu. |
| **Warunki końcowe**  |  Nowy kurs zostaje dodany do listy kursów i jest widoczny dla wykładowcy   |
| **Źródło ewentualnych problemów** |  Nieprawidłowe dane – system wyświetla komunikat o błędzie i prosi o uzupełnienie lub poprawienie danych  <br> Brak uprawnień – system blokuje dostęp do formularza i informuje o braku autoryzacji |

| **Przypadek użycia** |   Zarzadzanie Kursem  |
| -------------------- | --- |
| **Scenariusz**       |  Wykładowca wybiera opcje do zarzadzania plikami kursu  |
| **Warunki wstępne**  |   Wykładowca jest zalogowany oraz posiada dostep do zarzadzania plikami kursu  |
| **Niezmienniki**     |   Wykładowca wybiera opcje zarzadznia plikami kursu  |
| **Opis**             |   Wykładowca loguje się do systemu i przechodzi do wybranego kursu. Następnie wybiera z menu kursu opcję „Zarzadzanie pliki kursu”. System sprawdza uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania plikami, w którym dostępne są opcje dodawania, edycji oraz usuwania plików związanych z kursem.  |
| **Warunki końcowe**  |  Wykładwoca przechodzi do menu zarządzania plikami kursu   |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia dostępu do zarządzania plikami i informuje o braku autoryzacji  <br>Błąd w ładowaniu interfejsu – system cofa nas spowrotem do zarzadzanai kursem |

| **Przypadek użycia** |  Zarzadzanie Kursem    |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcję do zarządzania uczestnikami kursu  |
| **Warunki wstępne**  |  Wykładowca jest zalogowany oraz posiada dostęp do zarządzania uczestnikami kursu   |
| **Niezmienniki**     |   Wykładowca wybiera opcję zarządzania uczestnikami kursu  |
| **Opis**             |   	Wykładowca loguje się do systemu i przechodzi do wybranego kursu. W menu kursu wybiera opcję „Zarządzanie uczestnikami”. System weryfikuje uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje interfejs zarządzania uczestnikami kursu, umożliwiając dodawanie, usuwanie lub edytowanie listy uczestników.  |
| **Warunki końcowe**  |  Wykładowca przechodzi do menu zarządzania uczestnikami kursu   |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia dostępu do zarządzania plikami i informuje o braku autoryzacji <br>Błąd w ładowaniu interfejsu – system cofa nas spowrotem do zarzadzanai kursem |


# Stworz kurs - DeKa


| **Przypadek użycia** | Stwórz Kurs    |
| -------------------- | --- |
| **Scenariusz**       |  Utworzenie Kursu   |
| **Warunki wstępne**  |  Wykladowca ma dostep do tworzenia kursu   |
| **Niezmienniki**     |  Wykladowca wysyla zapytanie do serwera o utworzenie Kursu   |
| **Opis**             |  Wykładowca loguje się do systemu. Następnie przechodzi do panelu zarządzania kursami. Wybiera opcję „Utwórz nowy kurs”. Wprowadza wymagane dane kursu, takie jak nazwa, opis. Klikając przycisk „Zatwierdź”, wykładowca wysyła zapytanie do serwera o utworzenie kursu. System weryfikuje poprawność danych i uprawnienia wykładowcy. Jeśli dane są poprawne, system tworzy kurs i wyświetla komunikat o pomyślnym utworzeniu kursu.|
| **Warunki końcowe**  | 	Kurs zostaje utworzony,wykladowca otrzymuje komunikat o pomyslnym utworzeniu Kursu    |
| **Źródło ewentualnych problemów** | Błędne lub niepełne dane w formularzu – system wyświetla komunikat o błędzie i prosi o ponowne wprowadzenie danych <br>Brak wymaganych uprawnień – system odrzuca żądanie utworzenia kursu |


# Stworz skrzynke - DeKa

| **Przypadek użycia** |   Stwórz Skrzynkę  |
| -------------------- | --- |
| **Scenariusz**       |  Utworzenie skrzynki   |
| **Warunki wstępne**  |  Użytkownik ma dostęp do funkcji tworzenia skrzynki   |
| **Niezmienniki**     |  Użytkownik inicjuje proces tworzenia skrzynki   |
| **Opis**             |  Użytkownik loguje się do systemu i przechodzi do sekcji zarządzania skrzynkami. Wybiera opcję „Stwórz nową skrzynkę”. Wprowadza wymagane dane, takie jak nazwa i opis skrzynki. Klikając „Zatwierdź”, wysyła żądanie do serwera. System weryfikuje poprawność danych oraz uprawnienia użytkownika. Po pozytywnej weryfikacji skrzynka zostaje utworzona, a użytkownik otrzymuje komunikat o powodzeniu operacji.   |
| **Warunki końcowe**  |  Skrzynka zostaje utworzona, Wykladowca otrzymuje potwierdzenie   |
| **Źródło ewentualnych problemów** |  Błędne lub niepełne dane w formularzu – system wyświetla komunikat o błędzie i prosi o ponowne wprowadzenie danych <br> Brak uprawnień użytkownika – system odrzuca próbę utworzenia skrzynki|


# Zarzadzanie plikami kursu - DeKa


| **Przypadek użycia** |   Zarzadzanie plikami kursu  |
| -------------------- | --- |
| **Scenariusz**       |   Dodanie pliku   |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operację dodania pliku   |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i wybiera zakładkę „Pliki”. Następnie klika przycisk „Dodaj plik”, wybiera plik z lokalnego dysku i zatwierdza. System sprawdza format, rozmiar i uprawnienia. Po pomyślnej weryfikacji plik zostaje zapisany i powiązany z kursem.  |
| **Warunki końcowe**  |   Plik zostaje dodany do kursu, a wykładowca otrzymuje potwierdzenie operacji   |
| **Źródło ewentualnych problemów** | Nieobsługiwany format pliku – system odrzuca plik i wyświetla komunikat o dozwolonych typach.<br> Przekroczony maksymalny rozmiar pliku – system informuje o limicie i prosi o zmniejszenie rozmiaru.<br>Brak odpowiednich uprawnień – system uniemożliwia dodanie pliku i wyświetla komunikat o braku dostępu.|

| **Przypadek użycia** |   Zarzadzanie plikami kursu  |
| -------------------- | --- |
| **Scenariusz**       |   Usuniecie pliku   |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operację usunięcia pliku  |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i wybiera zakładkę „Pliki”. Na liście plików znajduje żądany plik i wybiera opcję „Usuń”. System prosi o potwierdzenie operacji, a po jego udzieleniu usuwa plik z bazy danych i serwera.  |
| **Warunki końcowe**  |  Plik zostaje trwale usunięty z kursu, a wykładowca otrzymuje komunikat o prawidlowym usunięcia   |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system blokuje próbę usunięcia i informuje o braku dostępu.<br>Plik nie istnieje – system zgłasza błąd, jeśli plik został wcześniej usunięty lub nie został odnaleziony.<br>Brak potwierdzenia usunięcia – system anuluje operację i nie usuwa pliku. |

| **Przypadek użycia** |  Zarzadzanie plikami kursu    |
| -------------------- | --- |
| **Scenariusz**       |   Edycja pliku  |
| **Warunki wstępne**  |   Wykładowca ma dostęp do systemu i odpowiednie uprawnienia do zarządzania plikami  |
| **Niezmienniki**     |   Wykładowca wykonuje operacje edycji pliku  |
| **Opis**             |   Wykładowca loguje się do systemu, przechodzi do panelu kursu i otwiera zakładkę „Pliki”. Wybiera plik, który chce edytować, i przechodzi do formularza edycji. Wprowadza zmiany, np. nową nazwę lub opis pliku, a następnie zapisuje zmiany. System weryfikuje dane i aktualizuje informacje o pliku.  |
| **Warunki końcowe**  |   Informacje o pliku zostają zaktualizowane, a wykładowca otrzymuje komunikat potwierdzający edycję |
| **Źródło ewentualnych problemów** |  |

# Zarzadzanie skrzynka plikow - DeKa

| **Przypadek użycia** |   Zarzadzanie skrzynka plikow   |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcję do zarządzania do zarzadzania plikami na skrzynce  |
| **Warunki wstępne**  |  Wykładowca posiada dostęp do zarzadzania plikami na skrzynce    |
| **Niezmienniki**     |  Wykładowca wybiera opcję do zarządzania do zarzadzania plikami na skrzynce   |
| **Opis**             |   Wykładowca przechodzi do wybranego kursu, który zawiera skrzynkę plików. W menu kursu wybiera opcję „Zarzadzanie plikami”. System weryfikuje uprawnienia wykładowcy oraz dostępność skrzynki. Po pozytywnej weryfikacji, system ładuje interfejs, który umożliwia wykładowcy zarządzanie plikami: dodawanie nowych plików, edytowanie istniejących, a także usuwanie plików z danej skrzynki.  |
| **Warunki końcowe**  |  Wykładowca przechodzi do menu zarzadzania plikami na skrzynce   |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia edycji pliku i informuje o braku dostępu.<br>Błąd w danych – system zgłasza błąd, jeśli wprowadzone dane (np. nazwa, opis) nie spełniają wymagań (np. zbyt długi tekst).<br>Problem z zapisem – system nie może zapisać zmian z powodu błędu, użytkownik jest proszony o zapisanie jeszcze raz<br>Brak wybranego pliku – system informuje, że wybrany plik nie istnieje lub został wcześniej usunięty.<br>Brak potwierdzenia zmian – system nie zapisuje zmian, jeśli użytkownik nie potwierdzi edycji w odpowiedni sposób. |




| **Przypadek użycia** |   Zarzadzanie skrzynka plikow   |
| -------------------- | --- |
| **Scenariusz**       |   Wykładowca wybiera opcję do tworzenia skrzynki  |
| **Warunki wstępne**  |  Wykładowca posiada dostęp do tworzenia nowej skrzynki    |
| **Niezmienniki**     |  Wykładowca wybiera opcję do tworzenia skrzynki   |
| **Opis**             |   Wykładowca loguje się do systemu i przechodzi do kursu, w którym chce utworzyć nową skrzynkę plików. W menu kursu wybiera opcję „Swtorz skrzynke”. System weryfikuje uprawnienia wykładowcy oraz dostępność kursu. Po pozytywnej weryfikacji system ładuje formularz tworzenia nowej skrzynki.  |
| **Warunki końcowe**  |  Wykładowca przechodzi do menu tworznia nowej skrzynki   |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia dostępu do tworzenia skrzynki i informuje wykładowcę o braku autoryzacji.<br>Błąd w dostępności kursu – system informuje, że kurs, w którym wykładowca chce utworzyć skrzynkę, nie jest dostępny.<br>Błąd w formularzu tworzenia skrzynki – system zgłasza błąd, jeśli wprowadzone dane (np. nazwa skrzynki) są niepoprawne lub niekompletne. |

# Zarzadzanie plikami(na skrzynce) - DeKa


| **Przypadek użycia** |   Zarzadzanie plikami   |
| -------------------- | --- |
| **Scenariusz**       |  Sprawdzenie pliku przez Wykladowce   |
| **Warunki wstępne**  |  Użytkownik zalogowany jako wykładowca, posiada dostęp do kursu i odpowiednich plików     |
| **Niezmienniki**     |  Wykładowca wybiera opcje do przegladania plikow na skrzynce  |
| **Opis**             |  Wykładowca loguje się do systemu i przechodzi do sekcji kursu, w którym chce sprawdzić plik. System weryfikuje dostęp wykładowcy do pliku. Po pozytywnej weryfikacji system wyświetla zawartość pliku, lub umożliwia jego pobranie.   |
| **Warunki końcowe**  |   Wykładowca dostaje dostep do zawartości pliku lub do pobrania go  |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia dostępu do pliku i informuje o braku autoryzacji.<br>Brak pliku – system zgłasza błąd, jeśli plik nie istnieje lub został usunięty.<br>Błąd w pobieraniu pliku – system nie może pobrać pliku z powodu problemów z siecią lub serwerem.<br>Uszkodzony plik – system wyświetla komunikat o uszkodzeniu pliku, uniemożliwiając jego otwarcie lub pobranie. |


| **Przypadek użycia** |   Zarzadzanie plikami   |
| -------------------- | --- |
| **Scenariusz**       |   Dodanie pliku przez studenta do skrznyki  |
| **Warunki wstępne**  |    Użytkownik zalogowany jako Student, posiada dostęp do kursu i dodawania plikow do skrzynki   |
| **Niezmienniki**     |    Student wybiera opcje dodania pliku do skrzynki |
| **Opis**             |   	Student loguje się do systemu. W menu kursu wybiera opcję „Dodaj plik do skrzynki”. System weryfikuje, czy student ma odpowiednie uprawnienia do dodawania plików do skrzynki. Po pozytywnej weryfikacji, student wybiera plik z urządzenia, który chce dodać do skrzynki. System sprawdza, czy plik spełnia wymagania (np. rozmiar, format). Po zatwierdzeniu pliku, system dodaje go do odpowiedniej skrzynki.  |
| **Warunki końcowe**  |    	Plik pomyślnie dodany do skrzynki plików w kursie |
| **Źródło ewentualnych problemów** | Brak odpowiednich uprawnień – system odmawia dostępu do funkcji dodawania pliku i informuje studenta o braku autoryzacji.<br>Niekompatybilny format pliku – system informuje studenta, jeśli plik ma nieobsługiwany format i prosi o wybór odpowiedniego pliku.<br>Zbyt duży plik – system zgłasza błąd, jeśli plik przekracza dozwolony rozmiar i prosi o wybór mniejszego pliku.<br>Brak przestrzeni w skrzynce – jeśli skrzynka plików jest pełna, system informuje o braku miejsca na dodanie nowego pliku. |


