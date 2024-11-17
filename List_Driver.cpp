#include <iostream>
#include "list342.h"
#include "Child.h"
using namespace std;

int main(int argc, char* argv[])
{
    //BuildList Test
    List342<int> fileints;
    fileints.BuildList("listint.txt");
    cout << fileints << endl;
    //Int Tests
    List342<int> nums;
    List342<int> numsAgain;
    int number = 32;
    nums.Insert(&number);
    int number2 = 21;
    nums.Insert(&number2);
    int number3 = 56;
    nums.Insert(&number3);
    int number4 = 7;
    nums.Insert(&number4);
    cout << nums << endl;
    numsAgain = nums;
    cout << numsAgain << endl;
    nums.Remove(32, number);
    numsAgain.Remove(7, number4);
    int number5 = 45;
    numsAgain.Insert(&number5);
    cout << nums << endl;
    cout << numsAgain << endl;
    nums.Merge(numsAgain);
    cout << nums << endl;
    List342<int> allNums(nums);
    //Check operators
    if(allNums != nums) cout << "ERROR" << endl;
    List342<int> addition;
    int num1 = 1;
    int num5 = 5;
    int num11 =11;
    addition.Insert(&num1);
    addition.Insert(&num5);
    addition.Insert(&num11);
    cout << addition << endl;
    allNums+= addition;
    cout << allNums << endl;
    List342<int> onemore;
    int num100 = 100;
    onemore.Insert(&num100);
    cout << onemore << endl;
    List342<int> final = allNums + onemore;
    cout << final << endl;

    cout << endl;
    //Provided Child Tests
    Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
    c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
    Child c5("Piqi", "Tangi", 7), c6("Russell", "Wilson", 13),
    c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
    Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
    List342<Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);
    cout << "class1: " << class1 << endl;
    if (!class1.Insert(&c1))
    {
    cout << "ERROR::: Duplicate" << endl;
    }
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);
    cout << "Class2: " << class2 << endl;
    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);
    cout << "class1 and 2 Merged: " << class1 << endl;
    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);
    if (class1.Remove(c1, c11))
    {
    cout << "Removed from class1, student " << c11 << endl;
    }
    cout << "class1: " << class1 << endl;
    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    cout << "soccer: " << soccer << endl;
    soccer += class1;
    cout << "soccer += class1 : " << soccer << endl;
    cout << "Class1: " << class1 << endl;
    List342<Child> football = soccer;
    if (football == soccer)
    {
    cout << "football: " << football << endl;
    }
    if (football.Peek(c6, c11))
    {
    cout << c11 << " is on the football team" << endl;
    }
    soccer.DeleteList();
    List342<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: " << numbers << endl;
    numbers.DeleteList();
}