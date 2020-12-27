// DesignPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

// --------------------------------------
//   모던 C++ 디자인 패턴
//
/// 참조 https://devjino.tistory.com/50 
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

