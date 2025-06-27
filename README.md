# מטלה 4 – מיכלים ואיטרטורים ב־C++

**מגיש:** לאון פסטרנק

**דוא"ל:** leonandsani@gmai.com

**תיאור:** פרויקט המדגים מימוש של מיכל גנרי עם איטרטורים מגוונים.

---

## 🧩 מבנה הפרויקט

- **MyContainer.hpp** – מימוש של מחלקה גנרית `MyContainer<T>` שתומכת:
  - בהוספה (`add`)
  - הסרה (`remove`)
  - הדפסה (`operator<<`)
  - החזרת גודל (`size`)
- **Iterators.hpp** – מימוש של שישה איטרטורים שונים:
  - `AscendingOrder`
  - `DescendingOrder`
  - `Order` (סדר הוספה)
  - `ReverseOrder` (סדר הוספה הפוך)
  - `SideCrossOrder`
  - `MiddleOutOrder`
- **Tests.cpp** – בדיקות עם `doctest` לכל הפונקציות והאיטרטורים.
- **Demo.cpp** – הדגמה מלאה של הקונטיינר וכל סוגי האיטרטורים.

---


## 📦 איך להשתמש

```bash
# הידור והרצת דמו
make
./Main

# הרצת טסטים
make run-tests

# בדיקת זיכרון
make valgrind

# ניקוי קבצים זמניים
make clean
