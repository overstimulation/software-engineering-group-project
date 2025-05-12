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

