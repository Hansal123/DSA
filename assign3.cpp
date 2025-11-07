/* 
Name - Hansal Kumar
Roll no - 23308
ProblemStatement:
 Createastudentdatabaseofatleast5SEITstudents,eachhaving:
 • RollNumber(Integer)
 • Name(String)
 • SGPA(Float)
 Performthefollowingoperationsonthearrayofstructure:
 a.Sortstudentsbyrollnumber(ascendingorder)usingBubbleSort.
 b.SortstudentsalphabeticallybynameusingInsertionSort.
 c.SortstudentsbySGPAindescendingorderusingQuickSorttogettop10toppers.
 d.SearchforstudentsbySGPAusingLinearSearchanddisplayallmatches.
 e.Searchforstudent(s)bynameusingnon-recursiveBinarySearch,displayallpartialmatches.
*/
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string fullName;
    int rollNo;
    float sgpa;
};

class StudentDatabase
{
private:
    Student hansalList[25];
    int total;

    void swapStudents(Student &x, Student &y)
    {
        Student temp = x;
        x = y;
        y = temp;
    }

public:
    // Input
    void inputData()
    {
        cout << "Enter total number of students: ";
        cin >> total;

        for (int i = 0; i < total; i++)
        {
            cout << "\nStudent " << i + 1 << " details:\n";
            cout << "Name: ";
            cin >> hansalList[i].fullName;
            cout << "Roll No: ";
            cin >> hansalList[i].rollNo;
            cout << "SGPA: ";
            cin >> hansalList[i].sgpa;
        }
    }

    // Display
    void showData()
    {
        cout << "\n--------------------------------------------\n";
        cout << left << setw(12) << "NAME" << setw(10) << "ROLL NO" << setw(10) << "SGPA" << endl;
        cout << "--------------------------------------------\n";
        for (int i = 0; i < total; i++)
        {
            cout << left << setw(12) << hansalList[i].fullName
                 << setw(10) << hansalList[i].rollNo
                 << setw(10) << hansalList[i].sgpa << endl;
        }
        cout << "--------------------------------------------\n";
    }

    // Bubble Sort (By Roll No)
    void sortByRoll()
    {
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = 0; j < total - i - 1; j++)
            {
                if (hansalList[j].rollNo > hansalList[j + 1].rollNo)
                    swapStudents(hansalList[j], hansalList[j + 1]);
            }
        }

        cout << "\nStudents sorted by Roll Number:\n";
        showData();
    }

    // Insertion Sort (By Name)
    void sortByName()
    {
        for (int i = 1; i < total; i++)
        {
            Student key = hansalList[i];
            int j = i - 1;

            while (j >= 0 && hansalList[j].fullName > key.fullName)
            {
                hansalList[j + 1] = hansalList[j];
                j--;
            }
            hansalList[j + 1] = key;
        }

        cout << "\nStudents sorted by Name:\n";
        showData();
    }

    // Linear Search (By SGPA)
    void findBySGPA()
    {
        float value;
        cout << "\nEnter SGPA to search: ";
        cin >> value;

        bool found = false;
        cout << "\nSearch Results (SGPA = " << value << "):\n";
        for (int i = 0; i < total; i++)
        {
            if (hansalList[i].sgpa == value)
            {
                cout << "Name: " << hansalList[i].fullName
                     << " | Roll: " << hansalList[i].rollNo
                     << " | SGPA: " << hansalList[i].sgpa << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No student found with that SGPA.\n";
    }

    // Binary Search (By Name)
    void findByName()
    {
        // Sort alphabetically first
        sortByName();

        string target;
        cout << "\nEnter name to search: ";
        cin >> target;

        int low = 0, high = total - 1;
        bool found = false;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (hansalList[mid].fullName == target)
            {
                cout << "\nStudent Found:\n";
                cout << "Name: " << hansalList[mid].fullName
                     << " | Roll: " << hansalList[mid].rollNo
                     << " | SGPA: " << hansalList[mid].sgpa << endl;
                found = true;
                break;
            }
            else if (hansalList[mid].fullName < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (!found)
            cout << "No student found with that name.\n";
    }

    // Partition for Quick Sort (by SGPA)
    int partitionSGPA(int low, int high)
    {
        float pivot = hansalList[high].sgpa;
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (hansalList[j].sgpa > pivot)
            {
                i++;
                swapStudents(hansalList[i], hansalList[j]);
            }
        }
        swapStudents(hansalList[i + 1], hansalList[high]);
        return i + 1;
    }

    // Quick Sort (By SGPA)
    void quickSortSGPA(int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partitionSGPA(low, high);
            quickSortSGPA(low, pivotIndex - 1);
            quickSortSGPA(pivotIndex + 1, high);
        }
    }

    void sortBySGPA()
    {
        quickSortSGPA(0, total - 1);
        cout << "\nStudents sorted by SGPA (Descending):\n";
        showData();
    }
};

int main()
{
    StudentDatabase db;
    db.inputData();

    cout << "\n---- Original Data ----\n";
    db.showData();

    db.sortByRoll();
    db.sortByName();
    db.findBySGPA();
    db.findByName();
    db.sortBySGPA();

    return 0;
}
