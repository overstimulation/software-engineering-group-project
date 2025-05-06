#Sprawdz oceny - DeKa
| **Przypadek użycia** | Stwórz Kurs    |
| -------------------- | --- |
| **Scenariusz**       |  Prawidlowe utworzenie Kursu   |
| **Warunki wstępne**  |  Wykladowca ma dostep do tworzenia kursu   |
| **Niezmienniki**     |  Wykladowca wysyla zapytanie do serwera o utworzenie Kursu   |
| **Opis**             |  Wykładowca loguje się do systemu. Następnie przechodzi do panelu zarządzania kursami. Wybiera opcję „Utwórz nowy kurs”. Wprowadza wymagane dane kursu, takie jak nazwa, opis. Klikając przycisk „Zatwierdź”, wykładowca wysyła zapytanie do serwera o utworzenie kursu. System weryfikuje poprawność danych i uprawnienia wykładowcy. Jeśli dane są poprawne, system tworzy kurs i wyświetla komunikat o pomyślnym utworzeniu kursu.|
| **Warunki końcowe**  | Wykladowca otrzymuje komunikat o pomyslnym utworzeniu Kursu    |


| **Przypadek użycia** | Stwórz Kurs    |
| -------------------- | --- |
| **Scenariusz**       |  Nieprawidlowe utworzenie Kursu   |
| **Warunki wstępne**  |  Wykladowca ma dostep do tworzenia kursu   |
| **Niezmienniki**     |  Wykladowca wysyla zapytanie do serwera o utworzenie Kursu   |
| **Opis**             |  Wykładowca loguje się do systemu. Następnie przechodzi do panelu zarządzania kursami. Wybiera opcję „Utwórz nowy kurs”. Wprowadza wymagane dane kursu, takie jak nazwa, opis. Klikając przycisk „Zatwierdź”, wykładowca wysyła zapytanie do serwera o utworzenie kursu. System weryfikuje poprawność danych i uprawnienia wykładowcy. Jeśli dane są nieprawidłowe, W przypadku błędu system informuje o niepowodzeniu i podaje przyczynę.   |
| **Warunki końcowe**  | Wykladowca otrzymuje komunikat o nie prawidlowych danych do utworzeniu Kursu    |




