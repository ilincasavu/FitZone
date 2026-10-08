# FitZone – Gym Management (Console App)

A console program written in C++ for managing a fitness gym called **FitZone**.
It lets you manage employees and members, browse classes and their prices,
and look up gym locations.

## Features

**Employee functions (menu 1)**
- Show an employee's salary by name
- Remove an employee
- List all members
- Show members enrolled in a given class
- Remove a member
- Add a new employee (with input validation)
- List employees sorted by salary (ascending)
- Search for an employee (name + phone number)
- Search for a member (name + phone number)

**Member functions (menu 2)**
- Show the equipment needed for a class
- Show gym locations in a given city
- Show classes by difficulty ("usor", "mediu", "dificil")
- Show classes in chronological order
- Show the price of a class
- Add a new member (with input validation)

**Classes (menu 3)** – list all classes
**Locations (menu 4)** – list all cities with a gym
**EXIT (0)** – quit

## Data files

### angajati.in – employees
One employee per line: "last_name first_name phone job salary"

### clase.in – classes
One class per line: "name difficulty price hours equipment"

- "difficulty" is one of usor, mediu, dificil
- "hours" is a time range such as 08-10; chronological sorting uses its first two characters
- "price" is in lei per session
- "equipment" is a single word

### membrii.in – members
One member per line: "last_name first_name phone classes"

### `locatii.in` – locations
One address per line (up to 99 characters)
