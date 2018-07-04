//
//  main.cpp
//  Group A
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "EuropeanOption.hpp"
#include "ArrayFuncs.hpp"
#include "../UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "../UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"
//#include "../UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
//#include "../UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <iostream>

int main()
{
    // BS stock option model (b = r):          Batch1    Batch2    Batch3    Batch4
    type_T T     = (type_T) 0.25;   //    T:   0.25      1.00      1.00      30.0
    type_K K     = (type_K) 65.0;   //    K:   65.0     100.0      10.0     100.0
    type_sig sig = (type_sig) 0.30; //  sig:   0.30      0.20      0.50      0.30
    type_r r     = (type_r) 0.08;   //    r:   0.08      0.00      0.12      0.08
    type_b b     = (type_b) 0.08;   //    b:   0.08      0.00      0.12      0.08
    type_S S     = (type_S) 5.00;   //    S:   60.0     100.0      5.00     100.0
    
    // Create and set an option with the specified values
    EuropeanOption option;
    option.SetOption(T, K, sig, r, b, S);

    // Create S_array and compute option price arrays
    long N = 50;      // Number of intervals
    type_S S_start    = (type_S) 0.0;
    type_S S_end      = (type_S) 50.0;
    type_S S_interval = (type_S) ((S_end-S_start)/N);
    
    vector<type_S> S_array1      = MeshArray(S_start, S_end, S_interval);
    vector<double> S_CallPrices1 = option.CallPriceEuro(S_array1);
    vector<double> S_PutPrices1  = option.PutPriceEuro(S_array1);
    
    // For compatibility with the provided code, convert vector<> to Vector<>
    Vector<double, long> S_array2(N+1, 0), S_CallPrices2(N+1, 0), S_PutPrices2(N+1, 0);
    for (long j = S_array2.MinIndex(); j <= S_array2.MaxIndex(); ++j)
    {
        S_array2[j] = S_array1[j];
        S_CallPrices2[j] = S_CallPrices1[j];
        S_PutPrices2[j] = S_PutPrices1[j];
    }
    
    // Print call prices:
    print(S_array2);
    print(S_CallPrices2);
    print(S_PutPrices2);
    
    /* // Exact solution:
     
     Variable(S)     Call Price      Put Price
     10              2.47991         1.34911
     11              3.20101         1.07022
     12              3.97996         0.84916
     13              4.80513         0.674338
     14              5.66702         0.536229
     15              6.55795         0.427155
     16              7.47177         0.340976
     17              8.40361         0.272816
     18              9.34962         0.218826
     19              10.3068         0.175982
     20              11.2727         0.141908
     21              12.2455         0.114747
     22              13.2238         0.0930416
     23              14.2064         0.0756513
     24              15.1925         0.0616812
     25              16.1812         0.0504283
     26              17.1721         0.0413397
     27              18.1648         0.0339792
     28              19.1588         0.0280021
     29              20.1539         0.0231356
     30              21.15           0.0191627
     31              22.1467         0.0159111
     32              23.144          0.013243
     33              24.1418         0.0110481
     34              25.14           0.00923813
     35              26.1385         0.00774197
     36              27.1373         0.00650231
     37              28.1363         0.00547278
     38              29.1354         0.00461585
     39              30.1347         0.00390101
     40              31.1341         0.00330341
     41              32.1336         0.00280276
     42              33.1332         0.00238249
     43              34.1328         0.00202896
     44              35.1325         0.001731
     45              36.1323         0.0014794
     46              37.1321         0.00126653
     47              38.1319         0.00108611
     48              39.1317         0.000932916     
     49              40.1316         0.000802612     
     50              41.1315         0.000691587   */
    
/*
    cout << "Print S, call prices, and put prices into Excel:\n";
 
    try
    {
        printPairExcel(S_array2, S_CallPrices2, S_PutPrices2, string("Option Price"), string("Asset Price (S)"), string("Call/Put Price"));
    }
    catch(DatasimException& e)
    {
        e.print();
    }
*/
    return 0;
}
