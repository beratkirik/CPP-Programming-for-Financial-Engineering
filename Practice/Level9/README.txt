#include <cstring> // size_t
cout' and stuff, just add std:: to cout, or simply #include <iostream> using namespace std;
.For generic class, gcc always ask you to add typename, like typename T::const_iterator i;

If you encounter Semantic Issue, like 'Declaration of "V" shadows template parameter' try comment out the template title 'template <class V, class I, class S>'

"Use of undeclared identifier 'Size' 'MinIndex' 'MaxIndex', try adjust those to (*this).Size, (*this).MinIndex, (*this).MaxIndex. all of them!


You should provide a document for each group, with a brief analysis of your code, i.e. why you picked such design, if the results are as expected, how the underlying theory makes sense to you (in Monte Carlo and FDM mostly) etc.

Screenshots of the results is fine. You don't have to export the output in the supplementary document. In some groups you need to export in excel, but that's irrelevant to the supplementary document. It's purpose is to serve like a read-me file that explains the project.

