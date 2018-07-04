// NewEuropeanOption.cpp
//
// A class that models a European option as an instance of an Entity object.
//
// (C) Datasim Component Technology BV 2003
//

#include "Entity.cpp"
#include <math.h>
#include <iostream>



// Kernel Functions (Haug)
double CallPrice() 
{

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	cout << "(d1, d2): " << d1 << ", " << d2 << endl;
	cout << "N(d1, d2): " << N(d1) << ", " << N(d2) << endl;

	return (U() * exp((b()-r())*T()) * N(d1)) - (K() * exp(-r() * T())* N(d2));

}

double PutPrice() 
{

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;
	cout << "(d1, d2): " << d1 << ", " << d2 << endl;
	cout << "N(d1, d2): " << N(d1) << ", " << N(d2) << endl;
	return (K() * exp(-r() * T())* N(-d2)) - (U() * exp((b()-r())*T()) * N(-d1));

}

double CallDelta() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;


	return exp((b()-r())*T()) * N(d1);
}

double PutDelta() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;

	return exp((b()-r())*T()) * (N(d1) - 1.0);
}

double CallGamma() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	return ( n(d1) * exp((b()-r())*T()) ) / (U() * tmp);
}

double PutGamma() 
{
	return CallGamma();
}


double CallVega() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;

	return (U() * exp((b()-r())*T()) * n(d1) * sqrt(T()) );
}

double PutVega() 
{
	return CallVega();
}

double CallTheta() 
{

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	double t1 =  (U() * exp((b()-r())*T() ) * n(d1) * sig() * 0.5 )/ sqrt(T());
	double t2 =  (b()-r())*(U() * exp((b()-r())*T()) * N(d1));
	double t3 =  r() * K() * exp(-r() * T()) * N(d2);

	return -(t1 + t2 + t3);
}


double PutTheta() 
{

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	double t1 =  (U() * exp( (b()-r())*T() ) * n(d1) * sig() * 0.5 )/ sqrt(T());
	double t2 =  (b()-r())*(U() * exp((b()-r())*T()) * N(-d1));
	double t3 =  r() * K() * exp(-r() * T()) * N(-d2);

	return t2 + t3 - t1;
}

double CallRho() 
{

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	if (b() != 0.0)
		return T() * K() * exp(-r() * T()) * N(d2);
	else
		return - T() * CallPrice();

}


double PutRho() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	if (b() != 0.0)
		return - T() * K() * exp(-r() * T()) * N(-d2);
	else
		return - T() * PutPrice();
}


double CallCoc() 
{

	double tmp = sig() * sqrt(T());
	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;

	return T() * U() * exp( (b()-r())*T() ) * N(d1);
}


double PutCoc() 
{
	double tmp = sig() * sqrt(T());
	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;

	return - T() * U() * exp((b()-r())*T()) * N(-d1);
}

double CallElasticity(double percentageMovement) 		
{

	return (CallDelta() * U()) /  percentageMovement;
}

double PutElasticity(double percentageMovement) 
{
	return (PutDelta() * U()) /  percentageMovement;
}

double CallStrike() 
{ // As a function of the strike price

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	return - exp(-r() * T()) * N(d2);
}

double PutStrike() 
{
	double tmp = sig() * sqrt(T());
	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	return exp(-r() * T()) * N(-d2);
}

double CallSecondStrike() 
{ // As a function of the strike price

	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	return ( n(d2) * exp(-r()* T()) )/( K() * sig() * sqrt(T()) );
}

double PutSecondStrike() 
{
	double tmp = sig() * sqrt(T());

	double d1 = ( log(U()/K()) + (b() + (sig()*sig())*0.5 ) * T() )/ tmp;
	double d2 = d1 - tmp;

	return ( n(d2) * exp(-r()* T()) )/( K() * sig() * sqrt(T()) );		
}

/////////////////////////////////////////////////////////////////////////////////////

void init() 
{	// Initialise all default values

	// Prototypical property names and values (hard-coded)
	r = Property<string, double> ("Interest rate", 0.08);
	sig= Property<string, double> ("Volatility",0.30);
	K = Property<string, double>("Strike Price", 65.0);
	T = Property<string, double>("Expiry date", 0.25);
	U = Property<string, double>("Underlying Asset", 60.0);		// U == stock in this case
	b = Property<string, double>("Cost of carry rate", r());	// Black and Scholes stock option model (1973)
	otyp = "C";													// European Call Option
	unam = "Stock Option with no Dividend";


}

void copy( ExactEuropeanOption& o2)
{

	r = Property<string,double>(o2.r);
	sig = Property<string,double>(o2.sig);	
	K = Property<string,double>(o2.K);
	T = Property<string,double>(o2.T);
	U = Property<string,double>(o2.U);
	b = Property<string,double>(o2.b);
	
	otyp = o2.otyp;
	unam = o2.unam;

	
}

ExactEuropeanOption() 
{ // Default call option

	init();
}

ExactEuropeanOption( ExactEuropeanOption& o2)
{ // Copy ructor

	copy(o2);
}

ExactEuropeanOption ( string& optionType)
{	// Create option type

	init();
	otyp = optionType;

	// Finger trouble option
	if (otyp == "c")
		otyp = "C";

}


ExactEuropeanOption ( string& optionType,  string& underlying)
{ // Create option type

	init();
	otyp = optionType;
	unam = underlying;
}

~ExactEuropeanOption()
{

}


ExactEuropeanOption& operator = ( ExactEuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double Price()  
{

	if (otyp == "C")
	{
	//	cout << "Call option\n";
		return CallPrice();
	}
	else
		return PutPrice();

}

double Delta()  
{
	if (otyp == "C")
		return CallDelta();
	else
		return PutDelta();

}


double Gamma()  
{
	if (otyp == "C")
		return CallGamma();
	else
		return PutGamma();

}

double Vega()  
{
	if (otyp == "C")
		return CallVega();
	else
		return PutVega();

}

double Theta()  
{
	if (otyp == "C")
		return CallTheta();
	else
		return PutTheta();

}

double Rho()  
{
	if (otyp == "C")
		return CallRho();
	else
		return PutRho();

}


double Coc()  
{ // Cost of carry

	if (otyp == "C")
		return CallCoc();
	else
		return PutCoc();

}

double Elasticity(double percentageMovement) 
{ // Elasticity

	if (otyp == "C")
		return CallElasticity(percentageMovement);
	else
		return PutElasticity(percentageMovement);

}

// The option's defining parameters
SimplePropertySet<string, double> properties() 
{
	SimplePropertySet<string, double> result;

	result.add (Property<string, double> (r.name(), r() ) );
	result.add (Property<string, double> (sig.name(), sig() ) );
	result.add (Property<string, double> (K.name(), K() ) );
	result.add (Property<string, double> (T.name(), T() ) );
	result.add (Property<string, double> (U.name(), U() ) );
	result.add (Property<string, double> (b.name(), b() ) );

	return result;

}


SimplePropertySet<string, double> propertylist() 
{

	SimplePropertySet<string, double> result;

	result.add (Property<string, double> ("Option Value", Price() ) );
	result.add (Property<string, double> ("Delta",Delta() ) );
	result.add (Property<string, double> ("Gamma",Gamma() ) );
	result.add (Property<string, double> ("Vega",Vega() ) );
	result.add (Property<string, double> ("Vega",Theta() ) );
	result.add (Property<string, double> ("Rho",Rho() ) );
	result.add (Property<string, double> ("Cost of Carry",Coc() ) );										// Cost of carry
	
	cout << "counbt " << result.Count();
	return result;

}

Vector<double> graph( string& sensitivity_type,  string& property,
					 Vector<double> parameter_range)
{
		curr = &T;		// Default x axis is time T

		if (property == "r")
			curr = &r;
		if (property == "sig")
			curr = &sig;
		if (property == "K")
			curr = &K;
		if (property == "T")
			curr = &T;
		if (property == "U")
			curr = &U;
		if (property == "b")
			curr = &b;

		// Save the value in the 'current' property 
		double memento = (*curr)();


		Vector<double> result (parameter_range.Size(), parameter_range.MinIndex());

		if (sensitivity_type == "Price")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Price();
			}
		}

	

		if (sensitivity_type == "Delta")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Delta();
			}
		}


		if (sensitivity_type == "Gamma")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Gamma();
			}
		}

		if (sensitivity_type == "Vega")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Vega();
			}
		}

	
		if (sensitivity_type == "Theta")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Theta();
			}
		}

		if (sensitivity_type == "Rho")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Rho();
			}
		}

		if (sensitivity_type == "Coc")
		{
			for (int i = parameter_range.MinIndex(); i <= parameter_range.MaxIndex(); i++)
			{
				(*curr)(parameter_range[i]);
				result[i] = Coc();
			}
		}

		// Now restore the old value of the property
		(*curr)(memento);

		return result;

}


// Modifier functions
void toggle()
{ // Change option type (C/P, P/C)

	if (otyp == "C")
		otyp = "P";
	else
		otyp = "C";
}


//////////// Gaussian functions /////////////////////////////////

double n(double x)  
{ 

	double A = 1.0/sqrt(2.0 * 3.1415);
	return A * exp(-x*x*0.5);

}

double N(double x)  
{ // The approximation to the cumulative normal distribution


	double a1 = 0.4361836;
	double a2 = -0.1201676;
	double a3 = 0.9372980;

	double k = 1.0/(1.0 + (0.33267 * x));
	
	if (x >= 0.0)
	{
		return 1.0 - n(x)* (a1*k + (a2*k*k) + (a3*k*k*k));
	}
	else
	{
		return 1.0 - N(-x);
	}

}

class NewEuropeanOption : public Entity<string, double>
{
public:
	NewEuropeanOption () { init();}

};
