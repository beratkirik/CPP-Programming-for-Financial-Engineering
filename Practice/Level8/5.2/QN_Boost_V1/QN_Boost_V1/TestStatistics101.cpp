//
//  TestStatistics101.cpp
//  QN_Boost_V1
//
//  First program test the boost statistics library.
//
//  Created by Changheng Chen on 2/8/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <boost/math/distributions/uniform.hpp>
#include <boost/math/distributions/bernoulli.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <boost/math/distributions.hpp> // All distributions and For non_member functions of distributions

#include <iostream>
using namespace std;

int main()
{
    // Don't forget to tell compiler which namespace
    using namespace boost::math;
    
    uniform_distribution<> myUniform(0.0, 1.0); // Default type ie 'double'
    cout << "Lower value: " << myUniform.lower() << ", upper value: " << myUniform.upper() << endl;
    
    // Choose another data type
    uniform_distribution<float> myUniform2(0.0, 1.0);
    cout << "Lower value: " << myUniform2.lower() << ", upper value: " << myUniform2.upper() << endl;
 
    // Distributional properties
    double x = 0.25;
    
    cout << "pdf of Uniform: " << pdf(myUniform, x) << endl;
    cout << "cdf of Uniform: " << cdf(myUniform, x) << endl;
    
    // Bernoulli distributions
    bernoulli_distribution<> myBernoulli(0.4);
    cout << "Probability of success: " << myBernoulli.success_fraction() << endl;
    
    int k = 0;
    cout << "pdf of Bernoulli: " << pdf(myBernoulli, k) << endl;
    cout << "cdf of Bernoulli: " << cdf(myBernoulli, k) << endl;
    
    // Choose precision
    cout.precision(8); // Number of values behind comma
    
    // Other properties
    cout << "\n***Uniform distribution: \n";
    cout << "mean: " << mean(myUniform) << endl;
    
    // ... more
    
    cout << "hazard: " << hazard(myUniform, x) << endl;
    
    // STUDENT
    students_t_distribution<float> myStudent(30);  // 30 degrees of freedom
    
    // Quantiles and conversions between significant levels (fractions, 0.05)
    // and confidence levels (in percentages, e.g. 95%)
    double Alpha = 0.25;
    cout << "Confidence l: " << quantile(myStudent, Alpha / 2) << endl;
    cout << "Confidence, in %: " << quantile(complement(myStudent, Alpha / 2)) << endl;
    
    // Required sample sizes for Students t-distribution
    double M = 1.2;   // True mean
    double Sm = 1.8;  // Sample mean
    double Sd = 2.4;  // Sample standard deviation
    
    try
    {
        double df = students_t::find_degrees_of_freedom (fabs(M-Sm), Alpha, Alpha, Sd);
        int dof = ceil(df) + 1; // ceil(x) == smallest integer not less than x
        cout << "One-sided degrees of freedom: " << dof << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
