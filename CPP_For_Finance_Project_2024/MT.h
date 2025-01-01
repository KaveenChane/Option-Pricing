#pragma once
#include <random>

class MT
{
private:
    std::mt19937 mt_;

    static MT* instancePointer;

    MT() {
        std::random_device rd;
        mt_.seed(rd());
    }
    ~MT() {};

    std::normal_distribution<double> normal_distribution_{ 0.0, 1.0 };
    std::uniform_real_distribution<double> uniform_real_distribution_{ 0.0,1.0 };


public:

    MT(const MT& obj) = delete;

    static MT* getInstance()
    {
        if (instancePointer == NULL)
        {
            instancePointer = new MT();
            return instancePointer;
        }
        else
        {
            return instancePointer;
        }
    }

    double static rand_unif() {
        return getInstance()->uniform_real_distribution_(getInstance()->mt_);
    };
    double static rand_norm() {
        return getInstance()->normal_distribution_(getInstance()->mt_);
    };

};