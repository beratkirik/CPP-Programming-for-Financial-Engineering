//
//  TestDistributions.cpp
//  Exercise 5
//
//  Created by Changheng Chen on 2/10/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/Poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // Don't forget to tell compiler which namespace
    using namespace boost::math;
    
    
    //============================ Normal Distribution =============================
    
    normal_distribution<> myNormal(1.0, 10.0); // Default type is 'double'
    
    cout << "Mean: " << mean(myNormal) << ", standard deviation: "
    << standard_deviation(myNormal) << endl;
    
    // Distributional properties
    double x = 10.25;
    
    cout << "pdf: " << pdf(myNormal, x) << endl;
    cout << "cdf: " << cdf(myNormal, x) << endl;
    
    // Choose another data type and now a N(0,1) variate
    normal_distribution<float> myNormal2;
    cout << "Mean: " << mean(myNormal2) << ", standard deviation: "
    << standard_deviation(myNormal2) << endl;
    
    cout << "pdf: " << pdf(myNormal2, x) << endl;
    cout << "cdf: " << cdf(myNormal2, x) << endl;
    
    // Choose precision
    cout.precision(10); // Number of values behind the comma
    
    // Other properties
    cout << "\n***normal distribution: \n";
    cout << "mean: " << mean(myNormal) << endl;
    cout << "variance: " << variance(myNormal) << endl;
    cout << "median: " << median(myNormal) << endl;
    cout << "mode: " << mode(myNormal) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myNormal) << endl;
    cout << "kurtosis: " << kurtosis(myNormal) << endl;
    cout << "characteristic function: " << chf(myNormal, x) << endl;
    cout << "hazard: " << hazard(myNormal, x) << endl << endl;
    
    
    //========================== Exponential distribution ===========================
    
    double scaleParameter = 0.5;
    exponential_distribution<> myExponential(scaleParameter); // Default type is 'double'
    
    cout << "Mean:" << mean(myExponential) << ",standard deviation: "
    << standard_deviation(myExponential) << endl;
    
    // Distributional properties
    cout << "pdf: " << pdf(myExponential, x) << endl;
    cout << "cdf: " << cdf(myExponential, x) << endl;
    
    // Choose another data type and now a N(0,1) variate
    exponential_distribution<float> myExponential2(1.0);
    cout << "Mean: " << mean(myExponential2) << ", standard deviation: "
    << standard_deviation(myExponential2) << endl;
    
    cout << "pdf: " << pdf(myExponential2, x) << endl;
    cout << "cdf: " << cdf(myExponential2, x) << endl;

    // Other properties
    cout << "\n***exponential distribution: \n";
    cout << "mean: " << mean(myExponential) << endl;
    cout << "variance: " << variance(myExponential) << endl;
    cout << "median: " << median(myExponential) << endl;
    cout << "mode: " << mode(myExponential) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "kurtosis: " << kurtosis(myExponential) << endl;
    cout << "characteristic function: " << chf(myExponential, x) << endl;
    cout << "hazard: " << hazard(myExponential, x) << endl;
    
    
    //============================= Gamma distribution =============================
    
    double alpha = 3.0;     // Shape parameter, k
    double beta = 0.5;      // Scale parameter, theta
    gamma_distribution<double> myGamma(alpha, beta);
    
    cout << "\n***gamma distribution: \n";
    double val = 13.0;
    cout << endl <<  "pdf: " << pdf(myGamma, val) << endl;
    cout << "cdf: " << cdf(myGamma, val) << endl;
    
    vector<double> pdfList;
    vector<double> cdfList;
    
    double start = 0.0;
    double end = 10.0;
    long N = 30;            // Number of subdivisions
    
    val = 0.0;
    double h = (end - start) / double(N);
    
    for (long j = 1; j <= N; ++j)
    {
        pdfList.push_back(pdf(myGamma, val));
        cdfList.push_back(cdf(myGamma, val));
        
        val += h;
    }
    
    for (long j = 0; j < pdfList.size(); ++j)
    {
        cout << pdfList[j] << ", ";
        
    }
    
    cout << "***" << endl;
    
    for (long j = 0; j < cdfList.size(); ++j)
    {
        cout << cdfList[j] << ", ";
    }
    
    
    //============================ Poisson distribution =============================
    
    double mean = 5;
    poisson_distribution<double> myPoisson(mean);
    
    val = 5.0;
    cout << "\n\n***Poisson distribution: \n";
    cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;
    cout << "cdf: " << cdf(myPoisson, val) << endl;
    
    vector<double> pdfList2;
    vector<double> cdfList2;
    
    double start2 = 0.0;
    double end2 = 10.0;
    long N2 = 30;            // Number of subdivisions
    
    val = 0;
    double h2 = (end2 - start2) / double(N2);
    
    for (long j = 1; j <= N2; ++j)
    {
        pdfList2.push_back(pdf(myPoisson, val));
        cdfList2.push_back(cdf(myPoisson, val));
        
        val += h2;
    }
    
    for (long j = 0; j < pdfList2.size(); ++j)
    {
        cout << pdfList2[j] << ", ";
        
    }
    
    cout << "***" << endl;
    
    for (long j = 0; j < cdfList2.size(); ++j)
    {
        cout << cdfList2[j] << ", ";
    }
    
    return 0;
}
