# 🎓 CDAC AC Roll Number Group Generator

> ⚠️ **Disclaimer:** This is a **strictly unofficial** project written for learning/practice purposes. It is **not affiliated with or endorsed by CDAC**. The output could be wrong — always verify against the official roll number list. Use at your own risk.



Link to check your roll numbers and groups : https://pastebin.com/mnkJJCnM



## 📌 What does this program do?

This is a simple C++ program that:
1. Reads a list of student names from a text file.
2. Cleans up and standardizes the names (fixes casing and formatting issues).
3. Sorts the names alphabetically.
4. Assigns each student a **roll number**.
5. Divides students into **groups of 10** (useful for lab batches, project teams, etc.) and prints them out group-wise.

This was built as a practice project while learning C++ — feel free to read through it, fork it, and improve it!

---

## 🛠 How it works (step by step)

### 1. Reading the file

```cpp
ifstream my_f("C:\\Users\\szzan\\eclipse-workspace\\RollNo\\src\\Student_List.txt");
```

- `ifstream` stands for **"input file stream"** — it's how C++ reads data *from* a file.
- `my_f.is_open()` checks if the file was successfully opened (important, because if the file path is wrong, the program should not try to read from it).
- `getline(my_f, line)` reads the file **one line at a time** and stores it in the variable `line`.

> 📁 **Note:** The file path is hardcoded (written directly in the code). If you run this on your own computer, you'll need to change this path to point to *your* copy of `Student_List.txt`.

### 2. Storing the names — what is a `vector`?

```cpp
vector<string> v;
```

A `vector` is like an **array that can grow or shrink automatically**. Unlike a normal C-style array (`string arr[100]`), you don't need to know the size in advance — you can just keep adding items to it with `.push_back()`, and it resizes itself behind the scenes.

Here, every name read from the file gets added to the vector `v` using:

```cpp
v.push_back(line);
```

### 3. Cleaning up the names

The names in the file weren't consistently formatted, so the code does two things to each name:

**a) Convert everything to UPPERCASE**

```cpp
for(char &c : s){
    c = toupper(c);
}
```

This loops through every character `c` in each string `s` and converts it to uppercase using `toupper()`. This is done because inconsistent casing (e.g., "john" vs "John" vs "JOHN") would mess up alphabetical sorting.

**b) Add a missing suffix (`_AC`)**

```cpp
string last_part = s.substr(sz - 3);
if(last_part != "_AC"){
    s = s + "_AC";
}
```

- `s.substr(sz - 3)` grabs the **last 3 characters** of the string (`substr` = "substring").
- If those last 3 characters aren't `"_AC"`, the code appends `"_AC"` to the end of the name.
- This is likely used to tag every student's name with their course code (`AC` batch), ensuring consistency even if some entries in the original file were missing it.

### 4. Sorting the names

```cpp
sort(v.begin(), v.end());
```

This uses the built-in `sort()` function (from the `<algorithm>` header) to sort the vector **alphabetically**, from A to Z. `v.begin()` and `v.end()` just mark the start and end of the vector — telling `sort()` to sort the *entire* list.

### 5. Assigning roll numbers & splitting into groups of 10

```cpp
int i = 1;
int g = 1;
cout << "Group " << g << endl;
g++;

for(string s : v){
    cout << "Roll no: " << i << " " << s << endl;
    if(i % 10 == 0){
        cout << endl << endl;
        cout << "Group " << g << endl;
        g++;
    }
    i++;
}
```

- `i` keeps track of the **roll number** (starts at 1, increases by 1 each loop).
- `g` keeps track of the **group number** (starts at 1).
- The loop prints each student with their roll number.
- Every time `i` is a multiple of 10 (`i % 10 == 0` — meaning it divides evenly by 10, i.e., 10, 20, 30...), the program starts a **new group** and increments `g`.

This effectively splits the whole sorted list into batches of 10 students per group.

---

---

## ▶️ How to run it

1. Make sure you have a C++ compiler installed (e.g., g++, or use an IDE like Eclipse CDT / Code::Blocks).
2. Update the file path in the code to point to your own `Student_List.txt`.
3. Compile and run:

```bash
g++ RollNo.cpp -o RollNo
./RollNo
```

---

## 📚 Concepts used in this project (for beginners)

| Concept | What it means |
|---|---|
| `ifstream` | Used to read data from a file |
| `vector<string>` | A dynamic (resizable) array of strings |
| `push_back()` | Adds an item to the end of a vector |
| `toupper()` | Converts a character to uppercase |
| `substr(pos)` | Extracts part of a string starting at position `pos` |
| `sort()` | Sorts elements of a container (like a vector) in order |
| `%` (modulo operator) | Gives the remainder of a division — used here to check "every 10th" student |

---

## 🚧 Known limitations

- The file path is hardcoded — it won't work unless you change it to your own system's path.
- No error handling if the file doesn't exist or is empty.
- Assumes every name should get an `_AC` suffix — may not suit every use case.
- This is a **learning project**, so the logic and grouping may not be 100% accurate. Please double-check against official records.

---

## 🙌 Contributing

This project was built for learning purposes. Suggestions, corrections, and pull requests are welcome — especially from fellow beginners looking to understand or improve the logic!

## 📥 Input format

The program expects a text file (`Student_List.txt`) with **one student name per line**, e.g.:
