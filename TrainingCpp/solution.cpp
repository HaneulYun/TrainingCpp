#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int bandageTime = bandage[0];
    int bandageHeal = bandage[1];
    int bandageExtra = bandage[2];

    int maxHealth = health;

    int prevAttackTime = 0;
    for (const auto& attack : attacks)
    {
        int time = attack[0] - prevAttackTime - 1;
        health += time * bandageHeal;
        health += (time / bandageTime) * bandageExtra;
        if (health > maxHealth)
            health = maxHealth;

        prevAttackTime = attack[0];

        health -= attack[1];
        if (health <= 0)
            return -1;
    }
    return health;
}

int main()
{
    return 0;
}