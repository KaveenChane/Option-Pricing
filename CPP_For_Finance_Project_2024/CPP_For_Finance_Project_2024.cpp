#include <iostream>
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"
#include "BinaryTree.h"
#include "CRRPricer.h"
#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "BlackScholesMCPricer.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"


/*
int main() {
    // Paramètres de l'option
    double expiry = 1.0;            // Date d'expiration en années
    double strike = 100.0;          // Prix d'exercice
    double assetPrice = 105.0;      // Prix actuel de l'actif sous-jacent
    double interestRate = 0.03;     // Taux d'intérêt sans risque
    double volatility = 0.2;        // Volatilité de l'actif

    try {
        // Création d'une option Call
        CallOption callOption(expiry, strike);
        // Création d'un pricer Black-Scholes pour l'option Call
        BlackScholesPricer callPricer(&callOption, assetPrice, interestRate, volatility);

        // Calcul du prix et du delta de l'option Call
        double callPrice = callPricer();
        double callDelta = callPricer.delta();

        std::cout << "Option Call:" << std::endl;
        std::cout << "Prix: " << callPrice << std::endl;
        std::cout << "Delta: " << callDelta << std::endl;

        // Création d'une option Put
        PutOption putOption(expiry, strike);
        // Création d'un pricer Black-Scholes pour l'option Put
        BlackScholesPricer putPricer(&putOption, assetPrice, interestRate, volatility);

        // Calcul du prix et du delta de l'option Put
        double putPrice = putPricer();
        double putDelta = putPricer.delta();

        std::cout << "\nOption Put:" << std::endl;
        std::cout << "Prix: " << putPrice << std::endl;
        std::cout << "Delta: " << putDelta << std::endl;

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    
    BinaryTree<double> tree;
    tree.setDepth(3);

    tree.setNode(0, 0, 1.0);
    tree.setNode(1, 0, 2.0);
    tree.setNode(1, 1, 3.0);
    tree.setNode(2, 0, 4.0);
    tree.setNode(2, 1, 5.0);
    tree.setNode(2, 2, 6.0);
    tree.setNode(3, 0, 7.0);
    tree.setNode(3, 1, 8.0);
    tree.setNode(3, 2, 9.0);
    tree.setNode(3, 3, 10.0);

    tree.display();
    
    return 0;
}
*/
int main() {
    {

        double S0(100.), K(101.), T(5.), r(0.01), sigma(0.1);
        CallOption opt1(T, K);
        PutOption opt2(T, K);


        std::cout << "European options 1" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            //int N(150);
            //double U = exp(sigma * sqrt(T / N)) - 1.0;
            //double D = exp(-sigma * sqrt(T / N)) - 1.0;
            //double R = exp(r * T / N) - 1.0;

            int N(5);
            double U = 0.05;
            double D = -0.045;
            double R = 0.01;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {
        std::cout << "Binary Tree" << std::endl << std::endl;
        BinaryTree<bool> t1;
        t1.setDepth(3);
        t1.setNode(1, 1, true);
        t1.display();
        t1.setDepth(5);
        t1.display();
        t1.setDepth(3);
        t1.display();


        BinaryTree<double> t2;
        t2.setDepth(2);
        t2.setNode(2, 1, 3.14);
        t2.display();
        t2.setDepth(4);
        t2.display();
        t2.setDepth(3);
        t2.display();

        BinaryTree<int> t3;
        t3.setDepth(4);
        t3.setNode(3, 0, 8);
        t3.display();
        t3.setDepth(2);
        t3.display();
        t3.setDepth(4);
        t3.display();

        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {

        double S0(100.), K(101.), T(5), r(0.01), sigma(0.1);
        EuropeanDigitalCallOption opt1(T, K);
        EuropeanDigitalPutOption opt2(T, K);


        std::cout << "European options 2" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(5);
            double U = 0.05;
            double D = -0.045;
            double R = 0.01;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {

        double S0(100), K(101.), T(5), r(0.01), sigma(0.1);
        std::vector<Option*> opt_ptrs;
        opt_ptrs.push_back(new CallOption(T, K));
        opt_ptrs.push_back(new PutOption(T, K));
        opt_ptrs.push_back(new EuropeanDigitalCallOption(T, K));
        opt_ptrs.push_back(new EuropeanDigitalPutOption(T, K));

        std::vector<double> fixing_dates;
        for (int i = 1; i <= 5; i++) {
            fixing_dates.push_back(0.1 * i);
        }
        opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
        opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));

        std::vector<double> ci;
        BlackScholesMCPricer* pricer;

        for (auto& opt_ptr : opt_ptrs) {
            std::string optionType = typeid(*opt_ptr).name(); //On recupere le type de l'option pour un meilleur affichage ici
            std::cout << "Processing option: " << optionType << std::endl;
            pricer = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
            do {
                //pricer->generate(1000000);
                pricer->generate(50);
                //pricer->generate(10);
                ci = pricer->confidenceInterval();
            } while (ci[1] - ci[0] > 1e-2);
            std::cout << "nb samples: " << pricer->getNbPaths() << std::endl;
            std::cout << "price: " << (*pricer)() << std::endl << std::endl;
            std::cout << "\n";
            delete pricer;
            delete opt_ptr;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;

    }

    {
        double S0(100.), K(101.), T(5.), r(0.01), sigma(0.1);
        std::vector<Option*> opt_ptrs;
        opt_ptrs.push_back(new CallOption(T, K));
        opt_ptrs.push_back(new PutOption(T, K));
        opt_ptrs.push_back(new EuropeanDigitalCallOption(T, K));
        opt_ptrs.push_back(new EuropeanDigitalPutOption(T, K));
        opt_ptrs.push_back(new AmericanCallOption(T, K));
        opt_ptrs.push_back(new AmericanPutOption(T, K));

        CRRPricer* pricer;

        for (auto& opt_ptr : opt_ptrs) {
            pricer = new CRRPricer(opt_ptr, 50, S0, r, sigma);

            pricer->compute();

            std::cout << "price: " << (*pricer)() << std::endl << std::endl;
            delete pricer;
            delete opt_ptr;

        }
    }
}
