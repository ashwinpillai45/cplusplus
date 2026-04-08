#include <iostream>
#include <stdint.h>

enum gun_list {assault_rifle, shotgun, sniper, pistols, melee, light_machine_gun, heavy_machine_gun};

class GameObject{
uint8_t weaponInventory[7];
public:
    GameObject(){

    }
    virtual void update(){

    }
    virtual bool use_Gun(){
        
    }
};

class Player : public GameObject{
    public:
        void update() override;
        bool use_Gun() override;

};

class Enemy : public GameObject{
    public:
        void update() override;
        bool use_Gun() override;
};

int main(){

    return 0;
};