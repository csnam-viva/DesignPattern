// DesignPattern.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>

// --------------------------------------
//   ��� C++ ������ ����
//
/// ���� https://devjino.tistory.com/50 
//  https://github.com/gilbutITbook/007028/blob/master/Behavioral/Strategy/strategy_static.cpp
//----------------------------------------

using namespace std;

template<typename T>
class Character
{
public:
    void attack()
    {
        Combat.PrepareWeapon();
        Combat.PrepareSkill();
    }
private:
    T Combat;

};

class Combat
{
protected:
    virtual void PrepareWeapon() = 0;
    virtual void PrepareSkill()=0;
    virtual void useSkill() = 0;
};

class ArcherCombat : public Combat
{
public:
    void PrepareWeapon() override
    {
        cout << "Archer Prepare Weapon \n";
    }
    void PrepareSkill() override
    {
        cout << "Archer PrepareKill \n";
    }
    void useSkill() override
    {
        cout << "Archar useSkill\n";
    }

};

int main()
{
    std::cout << "-----------------------\n";
    
    Character<ArcherCombat> archer;
    archer.attack();



    std::cout << "end-----------------------\n";
    return 0;
}

