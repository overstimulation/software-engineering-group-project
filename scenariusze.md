# Sprawdz oceny - Emzeey
| **Przypadek użycia** |  Sprawdz oceny   |
| -------------------- | --- |
| **Scenariusz**       |  Otrzymanie spisu ocen.   |
| **Warunki wstępne**  |  Student jest zalogowany.   |
| **Niezmienniki**     |  Student wybiera spis ocen do pokazania. Student zamyka spis.   |
| **Opis**             |  System wyświetla stronę profilu stidenta. Student wybiera jaki spis ocen chce zobaczyć. System wyświetla oceny. Student zamyka spis ocen.   |
| **Warunki końcowe**  |  Student sprawdził oceny. Panel ocen zostaje zamknięty.   |



# Wyloguj - Emzeey
| **Przypadek użycia** |  Wyloguj   |
| -------------------- | --- |
| **Scenariusz**       |  Pomyślne wylogowanie z systemu.   |
| **Warunki wstępne**  |  Użytkownik jest zalogowany.   |
| **Niezmienniki**     |  Użytkownik wybiera opcję wylogowania.   |
| **Opis**             |  Użytkownik wybiera opcję wylogowania. System zmienia status użytkownika na wylogowany i wyświetla powiadoemienie o wylogowaniu.   |
| **Warunki końcowe**  |  Użytkownik jest wylogowany.   |



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

