#ifndef CRRPRICER_H
#define CRRPRICER_H

#include <vector>
#include "BinaryTree.h"
#include "Option.h"

class CRRPricer {
private:
    Option* _option;
    int _depth;                // N
    double _asset_price;       // S0
    double _up;                // U
    double _down;              // D
    double _interest_rate;     // R
    BinaryTree<double> _tree;  // Tree to store computed option prices
    bool _computed;            // bool to check if compute() has been called

    bool hasArbitrage() const; // Helper to check for arbitrage
    
    BinaryTree<bool> exercise; //Modification for American option

public:
    // Constructor
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    CRRPricer(Option*, int, double, double, double);

    ~CRRPricer() = default;

    //Risk neutral prob
    double riskNeutralProbability() const;

    // Method to compute the CRR option price using the binomial model
    void compute();

    // Getter for H(n, i)
    double get(int n, int i);

    double StockPrice(int n, int i);

    double binomialCoefficient(int n, int k) const;

    // Overloaded operator() to return the option price
    double operator()(bool closed_form = false);

    // Method to access the exercise tree for American option
    bool getExercise(int n, int i);
};

#endif
