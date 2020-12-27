// DesignPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

class Command
{
public:
    virtual void execute(void) = 0;
    virtual ~Command() { };
};

class Ingredient : public Command
{
public:
    Ingredient(string amount, string ingredient) {
        _ingredient = ingredient;
        _amount = amount;
    }
    void execute() {
        cout << "ADD " << _amount << " of " << _ingredient << endl;
    }
private:
    string _ingredient;
    string _amount;
};

class CmdStack {
public:
    void add(Command* c)
    {
        Commands.push_back(c);
    }
    void undo() {

        Commands.pop_back();
    }
    void createRecipe()
    {
        for (vector<Command*>::size_type x = 0; x < Commands.size(); x++)
        {
            Commands[x]->execute();
        }
    }

private:
    vector<Command*> Commands;
};

int main_1()
{
    std::cout << "-----------------------\n";
    CmdStack list;

    Ingredient first1("3 cups", "rice");
    Ingredient first2("2 cups", "sugar");
    Ingredient first3("1 cups", "salt");

    list.add(&first1);
    list.add(&first2);
    list.add(&first3);
    list.undo();
    list.createRecipe();
    std::cout << "end-----------------------\n";
    return 0;
}

